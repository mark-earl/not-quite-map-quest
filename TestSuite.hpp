#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include "Digraph.hpp"
class Test {
    public:
        void testDijkstraFromAtlanta_GA(const Digraph& graph);
        void testDijkstraFromBoston_MA(const Digraph& graph);
        void testDijkstraFromChicago_IL(const Digraph& graph);
        void testDijkstraFromDenver_CO(const Digraph& graph);
        void testDijkstraFromLos_Angeles_CA(const Digraph& graph);
        void testDijkstraFromMiami_FL(const Digraph& graph);
        void testDijkstraFromNew_York_NY(const Digraph& graph);
        void testDijkstraFromSan_Francisco_CA(const Digraph& graph);
};

#endif // TEST_SUITE_HPP