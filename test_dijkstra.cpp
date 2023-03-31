/*
    @file test_dijkstra.cpp

    Test file for directed graph class
*/

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "Digraph.hpp"

// test suite
void test1(const Digraph& directedGraph);
void test2(const Digraph& directedGraph);

int main()
{
    std::ifstream dataFile;

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

    // -----------------------------------DELETE EVENTUALLY
    std::cout << "Before call to set garbage:\n"; directedGraph.display();
    directedGraph.setGarbage();
    std::cout << "Before call to reset edges:\n"; directedGraph.display();
    directedGraph.resetEdges();
    std::cout << "After call to reset edges:\n"; directedGraph.display();
    // -----------------------------------DELETE EVENTUALLY


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

    // test suite
    try {
        test1(directedGraph); // Los Angeles to Boston
        test2(directedGraph); // San Francisco to Miami
    }

    catch (std::logic_error& e) {
        std::cerr << e.what();
    }

    return 0;
}

void test1(const Digraph& directedGraph) {

    std::cout << "TEST 1. Los Angeles to Boston\n";
    int shortestDistance = directedGraph.dijkstra(4, 1);
    std::cout << "*** Final distance: " << shortestDistance << " miles.\n";

    // check dijkstra algorithm
    if (shortestDistance != 2602) {
        throw std::logic_error("TEST FAILED\n\n");
    }

    std::cout << "Test passed\n\n";
}
void test2(const Digraph& directedGraph) {

    std::cout << "TEST 2. San Francisco to Miami\n";
    int shortestDistance = directedGraph.dijkstra(7, 5);
    std::cout << "*** Final distance: " << shortestDistance << " miles.\n";

    // check dijkstra algorithm
    if (shortestDistance != 3056) {
        throw std::logic_error("TEST FAILED\n\n");
    }

    std::cout << "Test passed\n\n";
}
