PIP = pip3 --require-virtualenv
PY = python3


.PHONY: cavi
cavi:
	${PIP} install --no-deps .


.PHONY: all
all:
	${PIP} install .


.PHONY: dev
dev:
	${PIP} install .[dev]