TSORT=~/coreutils/build/tsort

build:
	gcc -o gen-rand-dag -O2 gen-rand-dag.c 
	cd ~/coreutils; make BUILD='tsort'

run:	build
	# $(TSORT) TEST0
	# $(TSORT) TEST1
	$(TSORT) TEST2
	# $(TSORT) TEST3
	# $(TSORT) TEST4
	# $(TSORT) TEST5

run_tests:	build
	rake del_rand_tests
	rake gen_rand_tests
	rake run_tests
