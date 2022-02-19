PIP = pip3
PY = python3


.PHONY: all
all:
	@${PIP} install .


.PHONY: dev
dev:
	@${PIP} install .[dev]