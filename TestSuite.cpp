#include "TestSuite.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <map>

enum CITIES {
    Atlanta_GA,
    Boston_MA,
    Chicago_IL,
    Denver_CO,
    Los_Angeles_CA,
    Miami_FL,
    New_York_NY,
    San_Francisco_CA,
};

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

void Test::testDijkstraFromAtlanta_GA(const Digraph& graph) {

    std::cout << "TEST 1. Calculating the shortest path to all cities starting from Atlanta_GA:\n";

    int correctValues[8] = { 0, 951, 606, 1514, 2348, 595, 760, 2461 };
    bool passed = true;

    for (int CITY = Atlanta_GA; CITY <= San_Francisco_CA; ++CITY) {
        int currentDist = graph.dijkstra(Atlanta_GA, CITY);
        std::cout << "Atlanta_GA -> " << std::setw(16) << std::left << CITIES[CITY] << " dist:" << currentDist;
        if (currentDist != correctValues[CITY]) {
            std::cout << " TEST FAILED\n";
            passed = false;
        }
    }

    if (passed) std::cout << "TEST 1 - Passed";
    std::cout << "\n\n";

}

void Test::testDijkstraFromBoston_MA(const Digraph& graph) {

    std::cout << "TEST 2. Calculating the shortest path to all cities starting from Boston_MA:\n";

    int correctValues[8] = { 951, 0, 860, 1768, 2602, 1281, 191, 2715 };
    bool passed = true;

    for (int CITY = Atlanta_GA; CITY <= San_Francisco_CA; ++CITY) {
        int currentDist = graph.dijkstra(Atlanta_GA, CITY);
        std::cout << "Boston_MA -> " << std::setw(16) << std::left << CITIES[CITY] << " dist:" << currentDist;
        if (currentDist != correctValues[CITY]) {
            std::cout << " TEST FAILED\n";
            passed = false;
        }
    }

    if (passed) std::cout << "TEST 2 - Passed\n\n";
    std::cout << "\n\n";
}

void Test::testDijkstraFromChicago_IL(const Digraph& graph) {

    std::cout << "TEST 3. Calculating the shortest path to all cities starting from Chicago_IL:\n";

    int correctValues[8] = { 606, 860, 0, 908, 1742, 1201, 722, 1855 };
    bool passed = true;

    for (int CITY = Atlanta_GA; CITY <= San_Francisco_CA; ++CITY) {
        int currentDist = graph.dijkstra(Atlanta_GA, CITY);
        std::cout << "Chicago_IL -> " << std::setw(16) << std::left << CITIES[CITY] << " dist:" << currentDist;
        if (currentDist != correctValues[CITY]) {
            std::cout << " TEST FAILED\n";
            passed = false;
        }
    }

    if (passed) std::cout << "TEST 3 - Passed\n\n";
    std::cout << "\n\n";
}
void Test::testDijkstraFromDenver_CO(const Digraph& graph) {

    std::cout << "TEST 4. Calculating the shortest path to all cities starting from Denver_CO:\n";

    int correctValues[8] = { 1514, 1768, 908, 0, 834, 2109, 1630, 957 };
    bool passed = true;

    for (int CITY = Atlanta_GA; CITY <= San_Francisco_CA; ++CITY) {
        int currentDist = graph.dijkstra(Atlanta_GA, CITY);
        std::cout << "Denver_CO -> " << std::setw(16) << std::left << CITIES[CITY] << " dist:" << currentDist;
        if (currentDist != correctValues[CITY]) {
            std::cout << " TEST FAILED\n";
            passed = false;
        }
    }

    if (passed) std::cout << "TEST 4 - Passed\n\n";
    std::cout << "\n\n";
}

void Test::testDijkstraFromLos_Angeles_CA(const Digraph& graph) {

    std::cout << "TEST 5. Calculating the shortest path to all cities starting from Los_Angeles_CA:\n";

    int correctValues[8] = { 2348, 2602, 1742, 834, 0, 2943, 2451, 349 };
    bool passed = true;

    for (int CITY = Atlanta_GA; CITY <= San_Francisco_CA; ++CITY) {
        int currentDist = graph.dijkstra(Atlanta_GA, CITY);
        std::cout << "Los_Angeles_CA -> " << std::setw(16) << std::left << CITIES[CITY] << " dist:" << currentDist;
        if (currentDist != correctValues[CITY]) {
            std::cout << " TEST FAILED\n";
            passed = false;
        }
    }

    if (passed) std::cout << "TEST 5 - Passed\n\n";
    std::cout << "\n\n";
}

void Test::testDijkstraFromMiami_FL(const Digraph& graph) {

    std::cout << "TEST 6. Calculating the shortest path to all cities starting from Miami_FL:\n";

    int correctValues[8] = { 595, 1281, 1201, 2109, 2943, 0, 1090, 3056 };
    bool passed = true;

    for (int CITY = Atlanta_GA; CITY <= San_Francisco_CA; ++CITY) {
        int currentDist = graph.dijkstra(Atlanta_GA, CITY);
        std::cout << "Miami_FL -> " << std::setw(16) << std::left << CITIES[CITY] << " dist:" << currentDist;
        if (currentDist != correctValues[CITY]) {
            std::cout << " TEST FAILED\n";
            passed = false;
        }
    }

    if (passed) std::cout << "TEST 6 - Passed\n\n";
    std::cout << "\n\n";
}
void Test::testDijkstraFromNew_York_NY(const Digraph& graph) {

    std::cout << "TEST 7. Calculating the shortest path to all cities starting from New_York_NY:\n";

    int correctValues[8] = { 760, 191, 722, 1630, 2451, 1090, 0, 2534 };
    bool passed = true;

    for (int CITY = Atlanta_GA; CITY <= San_Francisco_CA; ++CITY) {
        int currentDist = graph.dijkstra(Atlanta_GA, CITY);
        std::cout << "New_York_NY -> " << std::setw(16) << std::left << CITIES[CITY] << " dist:" << currentDist;
        if (currentDist != correctValues[CITY]) {
            std::cout << " TEST FAILED\n";
            passed = false;
        }
    }

    if (passed) std::cout << "TEST 7 - Passed\n\n";
    std::cout << "\n\n";
}

void Test::testDijkstraFromSan_Francisco_CA(const Digraph& graph) {

    std::cout << "TEST 8. Calculating the shortest path to all cities starting from San_Francisco_CA:\n";

    int correctValues[8] = { 2461, 2715, 1855, 957, 349, 3056, 2534, 0 };
    bool passed = true;

    for (int CITY = Atlanta_GA; CITY <= San_Francisco_CA; ++CITY) {
        int currentDist = graph.dijkstra(Atlanta_GA, CITY);
        std::cout << "San_Francisco_CA -> " << std::setw(16) << std::left << CITIES[CITY] << " dist:" << currentDist;
        if (currentDist != correctValues[CITY]) {
            std::cout << " TEST FAILED\n";
            passed = false;
        }
    }

    if (passed) std::cout << "TEST 8 - Passed\n\n";
    std::cout << "\n\n";
}
