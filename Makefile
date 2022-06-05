PIP = pip3 --require-virtualenv
PY = python3


.PHONY: cavi
cavi: rm-build
	${PIP} install --no-deps .


.PHONY: all
all: rm-build
	${PIP} install .


.PHONY: dev
dev: rm-build
	${PIP} install .[dev]


.PHONY: rm-build
rm-build:
	@rm -rf build


.PHONY: clean
clean:
	@find . | grep -E "(__pycache__|\.pyc|\.pyo$$)" | xargs rm -rf


.PHONY: clobber
clobber: clean rm-build
	@${PIP} uninstall cavi -y
	@find . | grep -E "\.egg-info$$" | xargs rm -rf


.PHONEY: test
test:
	${PY} -m pytest tests
