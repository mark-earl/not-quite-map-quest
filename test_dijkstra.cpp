/*
    @file test_dijkstra.cpp

    Test file for directed graph class
*/

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstring>
#include <limits>
#include "Digraph.hpp"
#include "TestSuite.hpp"

int main(int argc, char* argv[])
{
    // flag for nqmqBig.dat
    bool bigData = false;
    // flag for testing
    bool testSuite = false;

    // get command line arguments
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "big") == 0)
            bigData = true;
        if (strcmp(argv[i], "test") == 0)
            testSuite = true;
    }

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

        // test object
        Test test;

        // Let the user decide whether they want a full report or not
        char fullReport;

        do {
            // input prompt
            std::cout << "Show full report?[Y/N]\n";
            std::cout << "Full Report: All routes and distances are displayed\n";
            std::cout << "Short Report: Only the test headers are displayed\n";
            std::cout << "Please enter 'Y' or 'N':";
            std::cin >> fullReport;

            // input validation
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Invalid Input\n";
            }
        }
        while(fullReport != 'N' && fullReport != 'Y'); // only accept 'Y' or 'N'

        // run the appropriate test suite
        if(bigData)
            test.testSuite(directedGraph, fullReport, bigData);
        else
            test.testSuite(directedGraph, fullReport);
    }

    // menu gui
    else {

        char again = 'Y';

        while (again == 'Y') {

            std::cout << "Select Starting City:\n";
            for (int i = 0; i < directedGraph.getNumberOfVertices(); ++i)
                std::cout << i + 1 << ") " << directedGraph.getVertex(i)->getName() << '\n';

            int source = -1;

            do {
                // input prompt
                std::cin >> source;

                // input validation
                if(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Invalid Input, enter a number from the table above: ";
                    source = -1;
                }
            }
            while(source < 0 || source > directedGraph.getNumberOfVertices());

            std::cout << "Select Ending City:\n";
            for (int i = 0; i < directedGraph.getNumberOfVertices(); ++i)
                std::cout << i + 1 << ") " << directedGraph.getVertex(i)->getName() << '\n';

            int destination = -1;

            do {
                // input prompt
                std::cin >> destination;

                // input validation
                if(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Invalid Input, enter a number from the table above: ";
                    destination = -1;
                }
            }
            while(destination < 0 || destination > directedGraph.getNumberOfVertices());

            std::cout << "\nThe distance between " << directedGraph.getVertex(source - 1)->getName();
            std::cout << " and " << directedGraph.getVertex(destination - 1)->getName();
            std::cout << " is: " << directedGraph.dijkstra(source - 1, destination - 1) << "\n\n";

            do {
                // input prompt
                std::cout << "Again?[Y/N]\n";
                std::cout << "Please enter 'Y' or 'N':";
                std::cin >> again;
                std::cout << std::endl;

                // input validation
                if(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Invalid Input\n";
                }
            }
            while(again != 'N' && again != 'Y'); // only accept 'Y' or 'N'
        }
    }


    return 0;
}
