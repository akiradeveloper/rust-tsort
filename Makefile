TSORT=~/coreutils/build/tsort

build:
	cd ~/coreutils; make DONT_BUILD=tee uutils

run:	build
	$(TSORT) TEST0

run_tests:	build
	rake gen_rand_tests
	rake run_tests
