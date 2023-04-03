/*
    @file TestSuite.hpp

    Interface file for the test suite on dijkstra's algorithm
*/

#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include "Digraph.hpp"

class Test {
    public:
        // Tests dijkstra's algorithm
        // @param graph [in] The graph represented as an adjacency matrix
        // @param fullReport [in] Determines the output format [Y/N]
        // @param bigData [in] Determines the input for the algorithm (false by default)
        void testSuite(const Digraph& graph, char fullReport, bool bigData = false);
};

#endif // TEST_SUITE_HPP
