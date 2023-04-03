#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include "Digraph.hpp"

class Test {
    public:
        void testSuite(const Digraph& graph, char fullReport, bool bigData = false);
};

#endif // TEST_SUITE_HPP
