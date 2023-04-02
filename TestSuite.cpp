#include "TestSuite.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <map>

// Represents the city indexes as text
enum CITIES {
    Atlanta_GA,         // 0
    Boston_MA,          // 1
    Chicago_IL,         // 2
    Denver_CO,          // 3
    Los_Angeles_CA,     // 4
    Miami_FL,           // 5
    New_York_NY,        // 6
    San_Francisco_CA,   // 7
};

// Map the city indexes to their names
std::map<int, std::string> CITIES {
    {Atlanta_GA, "Atlanta_GA"},
    {Boston_MA, "Boston_MA"},
    {Chicago_IL, "Chicago_IL"},
    {Denver_CO, "Denver_CO"},
    {Los_Angeles_CA, "Los_Angeles_CA"},
    {Miami_FL, "Miami_FL"},
    {New_York_NY, "New_York_NY"},
    {San_Francisco_CA, "San_Francisco_CA"}
};

// Helper function. Tests the dijkstra() function from `source` to all cities in `graph`
// @param graph [in] Directed graph that stores all of the vertices (cities)
// @param source [in] The specified "starting point"
// @param correctValues [in] An array that holds the correct values for output of dijkstra's algorithm
void testTemplate(const Digraph& graph, const enum CITIES source, const int correctValues[]) {

    // formatting constants
    const int cityWidth = 34;
    const int valueWidth = 12;

    // header
    std::cout << "## TEST " << source + 1 << ". Starting from " << CITIES[source] << "\n";
    // table columns
    std::cout << "| Route                            |" << std::setw(valueWidth) << " Distance | Passed |\n";
    std::cout << "|:---------------------------------|" << std::setw(valueWidth) << std::setfill('-') << ":|:";
    std::cout << std::setw(valueWidth-3) << std::setfill('-') << ":|\n" << std::setfill(' ');

    // flag for entire test
    bool passed = true;

    // iterate through the cities
    for (int CITY = Atlanta_GA; CITY <= San_Francisco_CA; ++CITY) {

        // the current distance, for example: 595
        int dist = graph.dijkstra(source, CITY);

        // the current route, for example: Miami_FL -> Atlanta_GA
        std::string route = CITIES[source] + " -> " + CITIES[CITY];

        // output route
        std::cout << '|' << std::setw(cityWidth) << std::left << route;

        // output distance
        std::cout << '|' << std::setw(valueWidth - 2) << std::right << dist << '|';

        // output passed condition (OK or FAIL)
        if (dist != correctValues[CITY]) {
            std::cout <<std::setw(valueWidth-2) << std::right << "FAIL|\n";
            passed = false;
        }
        else {
            std::cout <<std::setw(valueWidth-2) << std::right << "OK|\n";
        }
    }

    // output test summary
    if (passed)
        std::cout << "\nTEST " << source + 1 << " - Passed";
    else
        std::cout << "\n!! TEST " << source + 1 << " - Failed !!";

    // padding
    std::cout << "\n\n";
}

// Tests dijkstra() functions using Atlanta_GA as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromAtlanta_GA(const Digraph& graph) {

    int correctValues[8] = { 0, 951, 606, 1514, 2348, 595, 760, 2461 };
    testTemplate(graph, Atlanta_GA, correctValues);

}

// Tests dijkstra() functions using Boston_MA as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromBoston_MA(const Digraph& graph) {

    int correctValues[8] = { 951, 0, 860, 1768, 2602, 1281, 191, 2715 };
    testTemplate(graph, Boston_MA, correctValues);
}

// Tests dijkstra() functions using Chicago_IL as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromChicago_IL(const Digraph& graph) {

    int correctValues[8] = { 606, 860, 0, 908, 1742, 1201, 722, 1855 };
    testTemplate(graph, Chicago_IL, correctValues);
}

// Tests dijkstra() functions using Denver_CO as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromDenver_CO(const Digraph& graph) {

    int correctValues[8] = { 1514, 1768, 908, 0, 834, 2109, 1630, 957 };
    testTemplate(graph, Denver_CO, correctValues);
}

// Tests dijkstra() functions using Los_Angeles_CA as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromLos_Angeles_CA(const Digraph& graph) {

    int correctValues[8] = { 2348, 2602, 1742, 834, 0, 2943, 2451, 349 };
    testTemplate(graph, Los_Angeles_CA, correctValues);
}

// Tests dijkstra() functions using Miami_FL as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromMiami_FL(const Digraph& graph) {

    int correctValues[8] = { 595, 1281, 1201, 2109, 2943, 0, 1090, 3056 };
    testTemplate(graph, Miami_FL, correctValues);
}

// Tests dijkstra() functions using New_York_NY as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromNew_York_NY(const Digraph& graph) {

    int correctValues[8] = { 760, 191, 722, 1630, 2451, 1090, 0, 2534 };
    testTemplate(graph, New_York_NY, correctValues);
}

// Tests dijkstra() functions using San_Francisco_CA as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromSan_Francisco_CA(const Digraph& graph) {

    int correctValues[8] = { 2461, 2715, 1855, 957, 349, 3056, 2534, 0 };
    testTemplate(graph, San_Francisco_CA, correctValues);
}
