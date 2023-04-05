# makefile for nqmq-mark-earl
# Refer to BUILD.md for instructions

CC = g++
FLAGS = -std=c++11

all: digraph.out clean

Digraph.o: Digraph.cpp
	@${CC} ${FLAGS} -c Digraph.cpp

test_suite.o: test_suite.cpp
	@${CC} ${FLAGS} -c test_suite.cpp

digraph.out: Digraph.o test_suite.o test_dijkstra.cpp
	@${CC} ${FLAGS} test_dijkstra.cpp *.o -o digraph.out
	@echo "# Available targets"
	@echo
	@echo "## Menu GUI:"
	@echo "\`make run\` 			- menu gui"
	@echo "\`make run_big\` 			- menu gui with nqmqBig.dat"
	@echo
	@echo "## Test Suites:"
	@echo "\`make test\` 			- test suite with nqmq.dat"
	@echo "\`make test_big\` 		- test suite with nqmqBig.dat"
	@echo "\`make test_summary\` 		- test suite with nqmq.dat with limited output"
	@echo "\`make test_big_summary\` 	- test suite with nqmqBig.dat with limited output"

clean:
	@rm -f *.o
	@rm -f *~
	@rm -f \#*

run:
	@./digraph.out
run_big:
	@./digraph.out big
test:
	@./digraph.out test
test_big:
	@./digraph.out big test
test_summary:
	@./digraph.out test summary
test_big_summary:
	@./digraph.out big test summary
