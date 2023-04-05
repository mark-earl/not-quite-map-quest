/*
    @file test_dijkstra.cpp

    Test file for directed graph class
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include <vector>
#include "Digraph.hpp"
#include "test_suite.hpp"

// Read data from either `nqmq.dat` or `nqmqBig.dat` into `directedGraph`
// @param directedGraph [out] The adjacency matrix storing the nodes
// @param bigData [in] Flag to determine wether to use `nqmq.dat` or `nqmqBig.dat`
void readData(Digraph& directedGraph, bool bigData);

// Runs a test suite on dijkstra's algorithm by trying all combinations of nodes in `directedGraph`
// @parm directedGraph [in] The adjacency matrix storing the nodes
// @param bigData [in] Flag to determine wether to use `nqmq.dat` or `nqmqBig.dat`
// @param fullReport [in] Flag to control output
void runTest(const Digraph& directedGraph, bool bigData, bool fullReport);

// Runs a menu-based UI for testing dijkstra's algorithm
// @parm directedGraph [in] The adjacency matrix storing the nodes
void runMenu(const Digraph& directedGraph);

int main(int argc, char* argv[])
{
    // flag for nqmqBig.dat
    bool bigData = false;
    // flags for testing
    bool testSuite = false;
    bool fullReport = true;

    // get command line arguments
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "big") == 0)
            bigData = true;
        if (strcmp(argv[i], "test") == 0)
            testSuite = true;
        if (strcmp(argv[i], "summary") == 0)
            fullReport = false;
    }

    // the adjacency matrix
    Digraph directedGraph;

    // read data into graph
    readData(directedGraph, bigData);

    // testing
    if (testSuite) {
        runTest(directedGraph, bigData, fullReport);
    }

    // menu gui
    else {
        runMenu(directedGraph);
    }

    return 0;
}

// Read data from either `nqmq.dat` or `nqmqBig.dat` into `directedGraph`
// @param directedGraph [out] The adjacency matrix storing the nodes
// @param bigData [in] Flag to determine wether to use `nqmq.dat` or `nqmqBig.dat`
void readData(Digraph& directedGraph, bool bigData) {

    // open the appropriate input file
    std::ifstream dataFile;
    if (bigData)
        dataFile.open("nqmqBig.dat");
    else
        dataFile.open("nqmq.dat");

    // the number of cities in the graph, each city is a node
    int numberOfNodes;
    dataFile >> numberOfNodes;

    // the name of each city
    std::string city;
    // directed graph to store the cities in
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
}

// Runs a test suite on dijkstra's algorithm by trying all combinations of nodes in `directedGraph`
// @parm directedGraph [in] The adjacency matrix storing the nodes
// @param bigData [in] Flag to determine wether to use `nqmq.dat` or `nqmqBig.dat`
// @param fullReport [in] Flag to control output
void runTest(const Digraph& directedGraph, bool bigData, bool fullReport) {

    // run the appropriate test suite
    if(bigData)
        testSuite(directedGraph, fullReport, bigData);
    else
        testSuite(directedGraph, fullReport);
}

// Runs a menu-based UI for testing dijkstra's algorithm
// @parm directedGraph [in] The adjacency matrix storing the nodes
void runMenu(const Digraph& directedGraph) {

    // allows for repeated use of the menu system
    char again = 'Y';

    // main loop
    while (again == 'Y' || again == 'y') {

        // values from the displayed menu
        std::vector<int> cities = {-1, -1};

        // display available cities
        for (int i = 0; i < directedGraph.getNumberOfVertices(); ++i)
                std::cout << i + 1 << ( i + 1 < 10 ? ")  ":") ") << directedGraph.getVertex(i)->getName() << '\n';

        // pick starting and ending cities
        for (int i = 0; i < cities.size(); ++i) {
            // select city
            std::cout << "Select " << (!i ? "Starting":"Ending") << " City: ";

            do {
                // input city index
                std::cin >> cities[i];

                // validate input
                if(std::cin.fail() || (cities[i] < 1 || cities[i] > directedGraph.getNumberOfVertices())) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Invalid Input, enter a number from the table above: ";
                    cities[i] = -1;
                }
            }
            while(cities[i] < 1 || cities[i] > directedGraph.getNumberOfVertices()); // range: [1, numberOfVertices]
        }

        // output distance between the two cities
        int sourceIndex = cities[0] - 1;
        int destinationIndex = cities[1] - 1;
        std::cout << "\nThe distance between " << directedGraph.getVertex(sourceIndex)->getName();
        std::cout << " and " << directedGraph.getVertex(destinationIndex)->getName();
        std::cout << " is: " << directedGraph.dijkstra(sourceIndex, destinationIndex) << "\n\n";

        // prompt user if they want to go again
        std::cout << "Again?[Y/N]:";

        do {

            // input choice
            std::cin >> again;

            // validate choice
            if(std::cin.fail() || again != 'N' && again != 'Y' && again != 'n' && again != 'y') {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Invalid Input, enter 'Y' or 'N':";
            }
        }
        while(again != 'N' && again != 'Y' && again != 'n' && again != 'y'); // only accept 'y', 'n', 'Y', and 'N'
    }
}
