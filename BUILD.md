# Build

This file contains instructions on how to build and run the test_dijkstra program.

This project supports an in-source build.

The commands are given in terms of `make`.

## Setup

Verify that you are in the source directory. The `make` command will look for the makefile in the working directory.

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
