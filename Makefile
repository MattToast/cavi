PIP = pip3 --require-virtualenv
PY = python3


.PHONEY: help
help:
	@echo "help ------- show this message"
	@echo "cavi ------- compile cavi w/o dependencies"
	@echo "all -------- compile cavi w/ dependencies"
	@echo "dev -------- compile cavi w/ dependencies and develop dependencies"
	@echo "rm-build --- remove the current build"
	@echo "clean ------ remove all cache files"
	@echo "clobber ---- 'clean' and 'rm-buiild' and uninstall 'cavi'"
	@echo "test ------- compile and run tests"


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
test: cavi
	${PY} -m pytest tests
