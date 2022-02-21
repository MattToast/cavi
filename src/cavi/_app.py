from __future__ import annotations

from threading import Event, Timer
from typing import TYPE_CHECKING, Dict, List
from cavi import get_gyro_x

from orbitalcoms import ComsMessage

from _cavi import (
    get_abort,
    get_acceleration_x,
    get_acceleration_y,
    get_acceleration_z,
    get_altitude,
    get_arm,
    get_gyro_y,
    get_gyro_z,
    get_latitude,
    get_launch,
    get_longitude,
    get_qdm,
    get_stabilize,
    get_temperature,
    set_abort,
    set_arm,
    set_launch,
    set_qdm,
    set_stabilize,
)

if TYPE_CHECKING:
    from orbitalcoms import LaunchStation


class App:
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
        if get_arm() or msg.ARMED:
            if not get_arm() and msg.ARMED is not None:
                # Set armed if not already
                # Redundent checks are for mypy
                set_arm(msg.ARMED)

            if not get_abort() and msg.ABORT:
                set_abort(msg.ABORT)

            if not get_qdm() and msg.QDM:
                set_qdm(msg.QDM)

            set_stabilize(msg.STAB)
            if not get_abort() and not get_qdm() and not get_launch() and msg.LAUNCH:
                set_launch(msg.LAUNCH)

            self.reset_timeout_thread()

    def construct_msg(self) -> ComsMessage:
        """Convience method to construct a message to send to GS"""
        return ComsMessage(
            ARMED=get_arm(),
            ABORT=get_abort(),
            QDM=get_qdm(),
            LAUNCH=get_launch(),
            STAB=get_stabilize(),
            DATA=self.construct_data(),
        )

    @staticmethod
    def construct_data() -> Dict[str, float | str | Dict[str, float]]:
        """Convience function for constructing a dictionary of all
        collected LS data
        """
        return {
            "altitide": get_altitude(),
            "temp": get_temperature(),
            "GPS": {
                "lat": get_latitude(),
                "lng": get_longitude(),
            },
            "gyro": {
                "X": get_gyro_x(),
                "Y": get_gyro_y(),
                "Z": get_gyro_z(),
            },
            "accel": {
                "X": get_acceleration_x(),
                "Y": get_acceleration_y(),
                "Z": get_acceleration_z(),
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
        set_stabilize(0)
        set_abort(1)
        set_qdm(1)

    def cleanup(self):
        """Called at end of a mission to dealloc resources"""
        self.ls.bind_queue(None)
        if self.recv_timer and self.recv_timer.is_alive():
            self.recv_timer.cancel()


def run_app(ls: LaunchStation, timeout: float | None = None):
    App.start(ls, timeout=timeout)
