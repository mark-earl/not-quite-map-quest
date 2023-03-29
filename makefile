CC = g++
FLAGS = -std=c++11

all: digraph.out clean

Digraph.o: Digraph.cpp
	@${CC} ${FLAGS} -c Digraph.cpp
	@echo [33%]\  Successfully created Digraph object file.

digraph.out: Digraph.o test_dijkstra.cpp
	@echo [66%]\  Building Executable.
	@${CC} ${FLAGS} test_dijkstra.cpp *.o -o digraph.out
	@echo [100%] Successfully built digraph.out.

clean:
	@echo Cleaning up...
	@rm -f *.o
	@rm -f *~
	@rm -f \#*

run:
	@echo Running tests:"\n"
	@./digraph.out
