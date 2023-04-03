#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include "Digraph.hpp"

class Test {

    public:
        void testSuite(const Digraph& graph);
        void testSuiteBig(const Digraph& graph);

    private:
        void failed() { allTestsPassed = false; }
        bool allTestsPassed = true;

};

#endif // TEST_SUITE_HPP
