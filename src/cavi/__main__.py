from orbitalcoms import create_serial_launch_station

import cavi._app as app


def main():
    app.run_app(create_serial_launch_station(port="/dev/ttyUSB0", baudrate=9600))


if __name__ == "__main__":
    main()
