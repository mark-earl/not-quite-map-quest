#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include "Digraph.hpp"
class Test {

    public:
        void testSuite(const Digraph& graph){
            testDijkstraFromAtlanta_GA(graph);
            testDijkstraFromBoston_MA(graph);
            testDijkstraFromChicago_IL(graph);
            testDijkstraFromDenver_CO(graph);
            testDijkstraFromLos_Angeles_CA(graph);
            testDijkstraFromMiami_FL(graph);
            testDijkstraFromNew_York_NY(graph);
            testDijkstraFromSan_Francisco_CA(graph);
        }

        void testSuiteBig(const Digraph& graph) {
            testDijkstraFromAkron(graph);
            testDijkstraFromBismarck(graph);
            testDijkstraFromBloomington(graph);
            testDijkstraFromChicago(graph);
            testDijkstraFromCincinnati(graph);
            testDijkstraFromColumbus(graph);
            testDijkstraFromDayton(graph);
            testDijkstraFromDesMoines(graph);
            testDijkstraFromDetroit(graph);
            testDijkstraFromEvansville(graph);
            testDijkstraFromFortWayne(graph);
            testDijkstraFromGary(graph);
            testDijkstraFromGrandRapids(graph);
            testDijkstraFromIndianapolis(graph);
            testDijkstraFromKalamazoo(graph);
            testDijkstraFromLouisville(graph);
            testDijkstraFromMilwaukee(graph);
            testDijkstraFromMinneapolis(graph);
            testDijkstraFromNashville(graph);
            testDijkstraFromOmaha(graph);
            testDijkstraFromPierre(graph);
            testDijkstraFromSaginaw(graph);
            testDijkstraFromSouthBend(graph);
            testDijkstraFromSaintLouis(graph);
            testDijkstraFromTerreHaute(graph);
            testDijkstraFromToledo(graph);
            testDijkstraFromWinnepeg(graph);
            testDijkstraFromYoungstown(graph);
        }

    private:

        // regular
        void testDijkstraFromAtlanta_GA(const Digraph& graph);
        void testDijkstraFromBoston_MA(const Digraph& graph);
        void testDijkstraFromChicago_IL(const Digraph& graph);
        void testDijkstraFromDenver_CO(const Digraph& graph);
        void testDijkstraFromLos_Angeles_CA(const Digraph& graph);
        void testDijkstraFromMiami_FL(const Digraph& graph);
        void testDijkstraFromNew_York_NY(const Digraph& graph);
        void testDijkstraFromSan_Francisco_CA(const Digraph& graph);

        // big
        void testDijkstraFromAkron(const Digraph& graph);
        void testDijkstraFromBismarck(const Digraph& graph);
        void testDijkstraFromBloomington(const Digraph& graph);
        void testDijkstraFromChicago(const Digraph& graph);
        void testDijkstraFromCincinnati(const Digraph& graph);
        void testDijkstraFromColumbus(const Digraph& graph);
        void testDijkstraFromDayton(const Digraph& graph);
        void testDijkstraFromDesMoines(const Digraph& graph);
        void testDijkstraFromDetroit(const Digraph& graph);
        void testDijkstraFromEvansville(const Digraph& graph);
        void testDijkstraFromFortWayne(const Digraph& graph);
        void testDijkstraFromGary(const Digraph& graph);
        void testDijkstraFromGrandRapids(const Digraph& graph);
        void testDijkstraFromIndianapolis(const Digraph& graph);
        void testDijkstraFromKalamazoo(const Digraph& graph);
        void testDijkstraFromLouisville(const Digraph& graph);
        void testDijkstraFromMilwaukee(const Digraph& graph);
        void testDijkstraFromMinneapolis(const Digraph& graph);
        void testDijkstraFromNashville(const Digraph& graph);
        void testDijkstraFromOmaha(const Digraph& graph);
        void testDijkstraFromPierre(const Digraph& graph);
        void testDijkstraFromSaginaw(const Digraph& graph);
        void testDijkstraFromSouthBend(const Digraph& graph);
        void testDijkstraFromSaintLouis(const Digraph& graph);
        void testDijkstraFromTerreHaute(const Digraph& graph);
        void testDijkstraFromToledo(const Digraph& graph);
        void testDijkstraFromWinnepeg(const Digraph& graph);
        void testDijkstraFromYoungstown(const Digraph& graph);
};

#endif // TEST_SUITE_HPP
