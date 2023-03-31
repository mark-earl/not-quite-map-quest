/*
    @file test_dijkstra.cpp

    Test file for directed graph class
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Digraph.hpp"

using std::ifstream;

void test1(const Digraph& directedGraph);
void test2(const Digraph& directedGraph);

int main()
{
    ifstream dataFile;

    dataFile.open("nqmq.dat");

    // the number of cities in the graph, each city is a node
    int numberOfNodes;
    dataFile >> numberOfNodes;

    // the name of each city
    Digraph directedGraph;
    std::string city;
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

    int sourceIndex;
    int destinationIndex;
    int distance;

    dataFile >> sourceIndex;
    dataFile >> destinationIndex;
    dataFile >> distance;

    // -1 delimits the list
    while (sourceIndex > -1) {

        // from source to destination
        directedGraph.addEdge(sourceIndex, destinationIndex, distance);
        // from destination back to source
        directedGraph.addEdge(destinationIndex, sourceIndex, distance);
        dataFile >> sourceIndex;
        dataFile >> destinationIndex;
        dataFile >> distance;
    }

    dataFile.close();

    // test suite
    test1(directedGraph); // Los Angeles to Boston
    test2(directedGraph); // San Francisco to Miami

    return 0;
}

void test1(const Digraph& directedGraph) {

    std::cout << "TEST 1. Los Angeles to Boston\n";
    int shortestDistance = directedGraph.dijkstra(4, 1);
    std::cout << "*** Final distance: " << shortestDistance << " miles.\n";

    // check dijkstra algorithm
    if (shortestDistance != 2602) {
        std::cout << "TEST FAILED\n\n";
        return;
    }

    std::cout << "Test passed\n\n";
}
void test2(const Digraph& directedGraph) {

    std::cout << "TEST 2. San Francisco to Miami\n";
    int shortestDistance = directedGraph.dijkstra(7, 5);
    std::cout << "*** Final distance: " << shortestDistance << " miles.\n";

    // check dijkstra algorithm
    if (shortestDistance != 3056) {
        std::cout << "TEST FAILED\n\n";
        return;
    }

    std::cout << "Test passed\n\n";
}
