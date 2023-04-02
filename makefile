CC = g++
FLAGS = -std=c++11

all: digraph.out clean

Digraph.o: Digraph.cpp
	@${CC} ${FLAGS} -c Digraph.cpp

TestSuite.o: TestSuite.cpp
	@${CC} ${FLAGS} -c TestSuite.cpp

digraph.out: Digraph.o TestSuite.o test_dijkstra.cpp
	@${CC} ${FLAGS} test_dijkstra.cpp *.o -o digraph.out
	@echo \# Available targets:
	@echo \`make run\`		- menu gui
	@echo \`make test\` 	- test suite
	@echo \`make run_big\` 	- menu gui with nqmqBig.dat
	@echo \`make test_big\` - test suite with nqmqBig.dat

clean:
	@rm -f *.o
	@rm -f *~
	@rm -f \#*

run:
	@./digraph.out
