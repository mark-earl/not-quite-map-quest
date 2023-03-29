/*
    @file test_dijkstra.cpp

    Test file for directed graph class
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Digraph.hpp"

using std::ifstream;

int main()
{
    Digraph directedGraph;
    ifstream dataFile;
    int numPoints, p, q, r;
    string city;

    dataFile.open("nqmq.dat");
    dataFile >> numPoints;

    for (int i = 0; i < numPoints; i++) {
        dataFile >> city;
        directedGraph.addVertex(city);
    }

    directedGraph.resetEdges();
    dataFile >> p;
    dataFile >> q;
    dataFile >> r;

    while (p > -1) {
        directedGraph.addEdge(p, q, r);
        directedGraph.addEdge(q, p, r);
        dataFile >> p;
        dataFile >> q;
        dataFile >> r;
    }

    dataFile.close();

    // test 1
    cout << "TEST 1. Los Angeles to Boston" << endl;
    p = directedGraph.dijkstra(4, 1);
    cout << "*** Final distance: " << p << " miles." << endl;
    if (p != 2602) cout << "TEST FAILED";
    else cout << "Test passed";
    cout << endl << endl;

    // test 2
    cout << "TEST 2. San Francisco to Miami" << endl;
    p = directedGraph.dijkstra(7, 5);
    cout << "*** Final distance: " << p << " miles." << endl;
    if (p != 3056) cout << "TEST FAILED";
    else cout << "Test passed";
    cout << endl << endl;
}
