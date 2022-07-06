from orbitalcoms import create_serial_launch_station, create_socket_launch_station
import sys

import cavi._app as app


def main() -> int:
    if len(sys.argv) > 1 and sys.argv[1].lower() == "socket":
        ls = create_socket_launch_station(host="127.0.1.1", port=5000)
    else:
        ls = create_serial_launch_station(port="/dev/ttyUSB0", baudrate=9600)

    with ls:
        app.run_app(ls)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
