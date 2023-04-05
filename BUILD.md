# Build

This file contains instructions on how to build and run the test_dijkstra program.

This project supports an in-source build.

The commands are given in terms of `make`.

## Setup

Verify that you are in the source directory. The `make` command will look for the [makefile](makefile) in the working directory.

Once done, you can then perform the build:

```console
make
```

You can now run one of the following targets:
- [run](#run)
- [run_big](#run_big)
- [test](#test)
- [test_big](#test_big)

## run

Test dijkstra's algorithm by selecting cities from nqmq.dat

```console
make run
```

To run on the command line:

```console
./digraph.out
```

## run_big

Test dijkstra's algorithm by selecting cities from nqmqBig.dat

```console
make run_big
```

To run on the command line:

```console
./digraph.out big
```

## test

Test dijkstra's algorithm using all possible city combinations in nqmq.dat

```console
make test
```

To run on the command line:

```console
./digraph.out test
```

## test_big

Test dijkstra's algorithm using all possible city combinations in nqmqBig.dat

```console
make test_big
```

To run on the command line:

```console
./digraph.out big test
```

## test_summary

Test dijkstra's algorithm using all possible city combinations in nqmq.dat with abbreviated output

```console
make test_summary
```

To run on the command line:

```console
./digraph.out test summary
```

## test_big_summary

Test dijkstra's algorithm using all possible city combinations in nqmqBig.dat with abbreviated output

```console
make test_big_summary
```

To run on the command line:

```console
./digraph.out big test summary
```

## Checking For Memory Leaks

Using `valgrind` you can check this program for memory leaks. Run the following command:

```console
g++ -std=c++17 -g  -Wall test_dijkstra.cpp Digraph.cpp TestSuite.cpp -o Debug
valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./Debug test big summary
```

NOTE: You will have to enter either 'Y' or 'N' when prompted
