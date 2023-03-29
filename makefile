# Build Instructions
#
# General Information
# 	-This is an "in source" build
#	-The clean target is a part of the `make` command
#	 and will remove any generated object files.
#
# Terminal Commands
# 	-To build executable: 	`make`
# 	-To run executable: 	`make run`


CC = g++
FLAGS = -std=c++11

all: digraph.out clean

Digraph.o: Digraph.cpp
	@${CC} ${FLAGS} -c Digraph.cpp
	@echo [33%]\  Successfully created Digraph object file.

digraph.out: Digraph.o test_dijkstra.cpp
	@echo [66%]\  Building Executable.
	@${CC} ${FLAGS} test_dijkstra.cpp *.o -o digraph.out
	@echo [100%] Successfully built digraph.out, type \`make run\` to execute.

clean:
	@echo Cleaning up...
	@rm -f *.o
	@rm -f *~
	@rm -f \#*

run:
	@./digraph.out
