from __future__ import annotations

from threading import Event, Timer
from typing import TYPE_CHECKING, Dict, List

from orbitalcoms import ComsMessage

from . import data, status

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
    def start(cls, ls: LaunchStation, timeout: float | None = None) -> None:
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
        if status.get_arm() or msg.ARMED:
            if not status.get_arm() and msg.ARMED is not None:
                # Set armed if not already
                # Redundent checks are for mypy
                status.set_arm(msg.ARMED)

            if not status.get_abort() and msg.ABORT:
                status.set_abort(msg.ABORT)

            if not status.get_qdm() and msg.QDM:
                status.set_qdm(msg.QDM)

            status.set_stabilize(msg.STAB)
            if (
                not status.get_abort()
                and not status.get_qdm()
                and status.get_stabilize()
                and not status.get_launch()
                and msg.LAUNCH
            ):
                status.set_launch(msg.LAUNCH)

    def construct_msg(self) -> ComsMessage:
        """Convience method to construct a message to send to GS"""
        return ComsMessage(
            ARMED=status.get_arm(),
            ABORT=status.get_abort(),
            QDM=status.get_qdm(),
            LAUNCH=status.get_launch(),
            STAB=status.get_stabilize(),
            DATA=self.construct_data(),
        )

    @staticmethod
    def construct_data() -> Dict[str, float | str | Dict[str, float]]:
        """Convience function for constructing a dictionary of all
        collected LS data
        """
        return {
            "altitide": data.get_altitude(),
            "temp": data.get_temperature(),
            "GPS": {
                "lat": data.get_latitude(),
                "lng": data.get_longitude(),
            },
            "gyro": {
                "X": data.get_gyro_x(),
                "Y": data.get_gyro_y(),
                "Z": data.get_gyro_z(),
            },
            "accel": {
                "X": data.get_acceleration_x(),
                "Y": data.get_acceleration_y(),
                "Z": data.get_acceleration_z(),
            },
        }

    def reset_timeout_thread(self) -> None:
        if self.recv_timer:
            self.recv_timer.cancel()
        self.recv_timer = Timer(interval=self.__TIMEOUT, function=self.panic)
        self.recv_timer.start()

    def panic(self) -> None:
        """Called when a message has not be recieved after given
        amount of time, or ortherwise the mission should be stopped imediatly
        """
        self.recv_timeout_event.set()
        self.ls.bind_queue(None)
        status.set_stabilize(0)
        status.set_abort(1)
        status.set_qdm(1)

    def cleanup(self) -> None:
        """Called at end of a mission to dealloc resources"""
        self.ls.bind_queue(None)
        if self.recv_timer and self.recv_timer.is_alive():
            self.recv_timer.cancel()
            self.recv_timer.join()
            self.recv_timer = None


def run_app(ls: LaunchStation, timeout: float | None = None) -> None:
    _App.start(ls, timeout=timeout)
