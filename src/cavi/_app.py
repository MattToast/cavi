from __future__ import annotations

from threading import Event, Timer
from typing import TYPE_CHECKING, Dict, List

from orbitalcoms import ComsMessage

import _cavi

if TYPE_CHECKING:
    from orbitalcoms import LaunchStation


class _App:
    __TIMEOUT: float = 60 * 10

    def __init__(self, ls: LaunchStation) -> None:
        self.ls = ls
        # TODO: Currently no way for mission to end, need to design API with GS/Comms
        self.mission_end = Event()
        self.recv_timeout_event = Event()
        self.recv_timer: Timer | None = None

    @classmethod
    def start(cls, ls: LaunchStation, timeout: float | None = None):
        """Convinence function for starting the application"""
        if timeout is not None and timeout > 0:
            cls.__TIMEOUT = timeout
        cls(ls).run()

    def run(self) -> None:
        """Main loop of the application. Responsible for reading, writing and
        cordinating data accros the GS/LS/Hardware
        """
        message_queue: List[ComsMessage] = []
        self.ls.bind_queue(message_queue)

        while not self.mission_end.is_set():
            while not self.recv_timeout_event.is_set() and message_queue:
                self.process_msg(message_queue.pop(0))

            if not self.ls.send(self.construct_msg()):
                # TODO: Logging or error handling here
                ...

            self.mission_end.wait(timeout=1)

        self.cleanup()

    def process_msg(self, msg: ComsMessage) -> None:
        """Proceess an incoming message from GS and preforms nessacary actions"""
        self.reset_timeout_thread()
        if _cavi.get_arm() or msg.ARMED:
            if not _cavi.get_arm() and msg.ARMED is not None:
                # Set armed if not already
                # Redundent checks are for mypy
                _cavi.set_arm(msg.ARMED)

            if not _cavi.get_abort() and msg.ABORT:
                _cavi.set_abort(msg.ABORT)

            if not _cavi.get_qdm() and msg.QDM:
                _cavi.set_qdm(msg.QDM)

            _cavi.set_stabilize(msg.STAB)
            if (
                not _cavi.get_abort()
                and not _cavi.get_qdm()
                and _cavi.get_stabilize()
                and not _cavi.get_launch()
                and msg.LAUNCH
            ):
                _cavi.set_launch(msg.LAUNCH)

    def construct_msg(self) -> ComsMessage:
        """Convience method to construct a message to send to GS"""
        return ComsMessage(
            ARMED=_cavi.get_arm(),
            ABORT=_cavi.get_abort(),
            QDM=_cavi.get_qdm(),
            LAUNCH=_cavi.get_launch(),
            STAB=_cavi.get_stabilize(),
            DATA=self.construct_data(),
        )

    @staticmethod
    def construct_data() -> Dict[str, float | str | Dict[str, float]]:
        """Convience function for constructing a dictionary of all
        collected LS data
        """
        return {
            "altitide": _cavi.get_altitude(),
            "temp": _cavi.get_temperature(),
            "GPS": {
                "lat": _cavi.get_latitude(),
                "lng": _cavi.get_longitude(),
            },
            "gyro": {
                "X": _cavi.get_gyro_x(),
                "Y": _cavi.get_gyro_y(),
                "Z": _cavi.get_gyro_z(),
            },
            "accel": {
                "X": _cavi.get_acceleration_x(),
                "Y": _cavi.get_acceleration_y(),
                "Z": _cavi.get_acceleration_z(),
            },
        }

    def reset_timeout_thread(self) -> None:
        if self.recv_timer:
            self.recv_timer.cancel()
        self.recv_timer = Timer(interval=self.__TIMEOUT, function=self.panic)
        self.recv_timer.start()

    def panic(self):
        """Called when a message has not be recieved after given
        amount of time, or ortherwise the mission should be stopped imediatly
        """
        self.recv_timeout_event.set()
        self.ls.bind_queue(None)
        _cavi.set_stabilize(0)
        _cavi.set_abort(1)
        _cavi.set_qdm(1)

    def cleanup(self):
        """Called at end of a mission to dealloc resources"""
        self.ls.bind_queue(None)
        if self.recv_timer and self.recv_timer.is_alive():
            self.recv_timer.cancel()
            self.recv_timer.join()
            self.recv_timer = None


def run_app(ls: LaunchStation, timeout: float | None = None):
    _App.start(ls, timeout=timeout)
