/*
    @file test_dijkstra.cpp

    Test file for directed graph class
*/

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstring>
#include "Digraph.hpp"
#include "TestSuite.hpp"

int main(int argc, char* argv[])
{
    bool bigFile = false;
    bool testSuite = false;

    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "big") == 0)
            bigFile = true;
        if (strcmp(argv[i], "test") == 0)
            testSuite = true;
    }

    std::ifstream dataFile;

    if (bigFile)
        dataFile.open("nqmqBig.dat");
    else
        dataFile.open("nqmq.dat");

    // the number of cities in the graph, each city is a node
    int numberOfNodes;
    dataFile >> numberOfNodes;

    // the name of each city
    std::string city;
    // directed graph to store the cities in
    Digraph directedGraph;
    for (int i = 0; i < numberOfNodes; i++) {
        dataFile >> city;
        directedGraph.addVertex(city);
    }

    // read in the first route

    // read in the source
    int sourceIndex;
    dataFile >> sourceIndex;

    // read in the destination
    int destinationIndex;
    dataFile >> destinationIndex;

    // read in the distance between the source and the destination
    int distance;
    dataFile >> distance;


    // -1 delimits the list
    while (sourceIndex > -1) {

        // from source to destination
        directedGraph.addEdge(sourceIndex, destinationIndex, distance);
        // from destination back to source
        directedGraph.addEdge(destinationIndex, sourceIndex, distance);

        // read in the next route
        dataFile >> sourceIndex;
        dataFile >> destinationIndex;
        dataFile >> distance;
    }

    // close the input file once done reading
    dataFile.close();

    // testing
    if (testSuite) {

        Test test;

        if(bigFile)
            test.testSuiteBig(directedGraph);
        else
            test.testSuite(directedGraph);
    }

    // menu gui
    else {

        if(bigFile)
            std::cout << "Simulation of big file menu gui.\n"; // @TODO run menu gui BIG
        else
            std::cout << "Simulation of menu gui.\n"; // @TODO run menu gui

    }

    return 0;
}
