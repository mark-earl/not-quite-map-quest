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

// Represents the city indexes as text
enum CITIES_BIG {
    Akron,              // 0
    Bismarck,           // 1
    Bloomington,        // 2
    Chicago,            // 3
    Cincinnati,         // 4
    Columbus,           // 5
    Dayton,             // 6
    DesMoines,          // 7
    Detroit,            // 8
    Evansville,         // 9
    FortWayne,          // 10
    Gary,               // 11
    GrandRapids,        // 12
    Indianapolis,       // 13
    Kalamazoo,          // 14
    Louisville,         // 15
    Milwaukee,          // 16
    Minneapolis,        // 17
    Nashville,          // 18
    Omaha,              // 19
    Pierre,             // 20
    Saginaw,            // 21
    SouthBend,          // 22
    SaintLouis,         // 23
    TerreHaute,         // 24
    Toledo,             // 25
    Winnepeg,           // 26
    Youngstown          // 27
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

// Map the city indexes to their names
std::map<int, std::string> CITIES_BIG {
    {Akron, "Akron"},
    {Bismarck, "Bismarck"},
    {Bloomington, "Bloomington"},
    {Chicago, "Chicago"},
    {Cincinnati, "Cincinnati"},
    {Columbus, "Columbus"},
    {Dayton, "Dayton"},
    {DesMoines, "Des Moines"},
    {Detroit, "Detroit"},
    {Evansville, "Evansville"},
    {FortWayne, "Fort Wayne"},
    {Gary, "Gary"},
    {GrandRapids, "Grand Rapids"},
    {Indianapolis, "Indianapolis"},
    {Kalamazoo, "Kalamazoo"},
    {Louisville, "Louisville"},
    {Milwaukee, "Milwaukee"},
    {Minneapolis, "Minneapolis"},
    {Nashville, "Nashville"},
    {Omaha, "Omaha"},
    {Pierre, "Pierre"},
    {Saginaw, "Saginaw"},
    {SouthBend, "South Bend"},
    {SaintLouis, "Saint Louis"},
    {TerreHaute, "Terre Haute"},
    {Toledo, "Toledo"},
    {Winnepeg, "Winnepeg"},
    {Youngstown, "Youngstown"}
};

const int vertices = 8;
const int verticesBig = 28;

// Helper function. Tests the dijkstra() function from `source` to all cities in `graph`
// @param graph [in] Directed graph that stores all of the vertices (cities)
// @param source [in] The specified "starting point"
// @param correctValues [in] An array that holds the correct values for output of dijkstra's algorithm
void testTemplate(const Digraph& graph, const enum CITIES source, const int correctValues[]) {

    // formatting constants
    const int cityWidth = 36;
    const int valueWidth = 12;

    // header
    std::cout << "## TEST " << source + 1 << ". Starting from " << CITIES[source] << "\n";
    // table columns
    std::cout << "| Route                              |" << std::setw(valueWidth) << " Distance | Passed |\n";
    std::cout << "|:-----------------------------------|" << std::setw(valueWidth) << std::setfill('-') << ":|:";
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

// Helper function. Tests the dijkstra() function from `source` to all cities in `graph`
// @param graph [in] Directed graph that stores all of the vertices (cities)
// @param source [in] The specified "starting point"
// @param correctValues [in] An array that holds the correct values for output of dijkstra's algorithm
void testTemplateBig(const Digraph& graph, const enum CITIES_BIG source, const int correctValues[]) {

    // formatting constants
    const int cityWidth = 36;
    const int valueWidth = 12;

    // header
    std::cout << "## TEST " << source + 1 << ". Starting from " << CITIES_BIG[source] << "\n";
    // table columns
    std::cout << "| Route                              |" << std::setw(valueWidth) << " Distance | Passed |\n";
    std::cout << "|:-----------------------------------|" << std::setw(valueWidth) << std::setfill('-') << ":|:";
    std::cout << std::setw(valueWidth-3) << std::setfill('-') << ":|\n" << std::setfill(' ');

    // flag for entire test
    bool passed = true;

    // iterate through the cities
    for (int CITY = Atlanta_GA; CITY <= Youngstown; ++CITY) {

        // the current distance, for example: 595
        int dist = graph.dijkstra(source, CITY);


        // the current route, for example: Miami_FL -> Atlanta_GA
        std::string route = CITIES_BIG[source] + " -> " + CITIES_BIG[CITY];

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

// Tests dijkstra() function using Atlanta_GA as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromAtlanta_GA(const Digraph& graph) {

    int correctValues[vertices] = { 0, 951, 606, 1514, 2348, 595, 760, 2461 };
    testTemplate(graph, Atlanta_GA, correctValues);

}

// Tests dijkstra() function using Boston_MA as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromBoston_MA(const Digraph& graph) {

    int correctValues[vertices] = { 951, 0, 860, 1768, 2602, 1281, 191, 2715 };
    testTemplate(graph, Boston_MA, correctValues);
}

// Tests dijkstra() function using Chicago_IL as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromChicago_IL(const Digraph& graph) {

    int correctValues[vertices] = { 606, 860, 0, 908, 1742, 1201, 722, 1855 };
    testTemplate(graph, Chicago_IL, correctValues);
}

// Tests dijkstra() function using Denver_CO as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromDenver_CO(const Digraph& graph) {

    int correctValues[vertices] = { 1514, 1768, 908, 0, 834, 2109, 1630, 957 };
    testTemplate(graph, Denver_CO, correctValues);
}

// Tests dijkstra() function using Los_Angeles_CA as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromLos_Angeles_CA(const Digraph& graph) {

    int correctValues[vertices] = { 2348, 2602, 1742, 834, 0, 2943, 2451, 349 };
    testTemplate(graph, Los_Angeles_CA, correctValues);
}

// Tests dijkstra() function using Miami_FL as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromMiami_FL(const Digraph& graph) {

    int correctValues[vertices] = { 595, 1281, 1201, 2109, 2943, 0, 1090, 3056 };
    testTemplate(graph, Miami_FL, correctValues);
}

// Tests dijkstra() function using New_York_NY as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromNew_York_NY(const Digraph& graph) {

    int correctValues[vertices] = { 760, 191, 722, 1630, 2451, 1090, 0, 2534 };
    testTemplate(graph, New_York_NY, correctValues);
}

// Tests dijkstra() function using San_Francisco_CA as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromSan_Francisco_CA(const Digraph& graph) {

    int correctValues[vertices] = { 2461, 2715, 1855, 957, 349, 3056, 2534, 0 };
    testTemplate(graph, San_Francisco_CA, correctValues);
}

/*
    BIG DATA
*/

// Tests dijkstra() function using Akron as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromAkron(const Digraph& graph) {

    int correctValues[verticesBig] = { 0, 1328, 335, 546, 194, 114, 184, 981, 195, 452, 405, 437, 304, 284, 270, 277, 620, 901, 428, 1113, 1295, 279, 424, 519, 355, 137, 1332, 38};
    testTemplateBig(graph, Akron, correctValues);
}

// Tests dijkstra() function using Bismarck as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromBismarck(const Digraph& graph) {

    int correctValues[verticesBig] = { 1328, 0, 1300, 782, 1134, 1214, 1164, 670, 1342, 1417, 1370, 1402, 1425, 1249, 1369, 1051, 758, 427, 1122, 581, 211, 1426, 1389, 1044, 1320, 1284, 369, 1366};
    testTemplateBig(graph, Bismarck, correctValues);
}

// Tests dijkstra() function using Bloomington as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromBloomington(const Digraph& graph) {

    int correctValues[verticesBig] = { 335, 1300, 0, 518, 166, 221, 151, 953, 306, 119, 172, 198, 227, 51, 171, 249, 592, 873, 400, 1085, 1267, 308, 191, 491, 58, 271, 1304, 373};
    testTemplateBig(graph, Bloomington, correctValues);
}

// Tests dijkstra() function using Chicago as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromChicago(const Digraph& graph) {

    int correctValues[verticesBig] = { 546, 782, 518, 0, 352, 432, 382, 435, 560, 635, 588, 620, 643, 467, 587, 269, 74, 355, 420, 567, 749, 644, 607, 262, 538, 502, 786, 584};
    testTemplateBig(graph, Chicago, correctValues);
}

// Tests dijkstra() function using Cincinnati as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromCincinnati(const Digraph& graph) {

    int correctValues[verticesBig] = { 194, 1134, 166, 352, 0, 80, 30, 787, 208, 283, 236, 268, 291, 115, 235, 83, 426, 707, 234, 919, 1101, 292, 255, 325, 186, 150, 1138, 232};
    testTemplateBig(graph, Cincinnati, correctValues);
}

// Tests dijkstra() function using Columbus as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromColumbus(const Digraph& graph) {

    int correctValues[verticesBig] = { 114, 1214, 221, 432, 80, 0, 70, 867, 168, 338, 291, 323, 277, 170, 243, 163, 506, 787, 314, 999, 1181, 252, 310, 405, 241, 110, 1218, 152};
    testTemplateBig(graph, Columbus, correctValues);
}

// Tests dijkstra() function using Dayton as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromDayton(const Digraph& graph) {

    int correctValues[verticesBig] = { 184, 1164, 151, 382, 30, 70, 0, 817, 178, 268, 221, 253, 276, 100, 220, 113, 456, 737, 264, 949, 1131, 262, 240, 355, 171, 120, 1168, 222};
    testTemplateBig(graph, Dayton, correctValues);
}

// Tests dijkstra() function using DesMoines as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromDesMoines(const Digraph& graph) {

    int correctValues[verticesBig] = { 981, 670, 953, 435, 787, 867, 817, 0, 995, 1070, 1023, 1055, 1078, 902, 1022, 704, 361, 252, 855, 132, 492, 1079, 1042, 697, 973, 937, 680, 1019};
    testTemplateBig(graph, DesMoines, correctValues);
}

// Tests dijkstra() function using Detroit as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromDetroit(const Digraph& graph) {

    int correctValues[verticesBig] = { 195, 1342, 306, 560, 208, 168, 178, 995, 0, 423, 376, 408, 147, 255, 135, 291, 634, 915, 442, 1127, 1309, 98, 395, 533, 326, 58, 1346, 233};
    testTemplateBig(graph, Detroit, correctValues);
}

// Tests dijkstra() function using Evansville as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromEvansville(const Digraph& graph) {

    int correctValues[verticesBig] = { 452, 1417, 119, 635, 283, 338, 268, 1070, 423, 0, 190, 277, 344, 168, 288, 366, 709, 990, 517, 1202, 1384, 425, 269, 608, 113, 388, 1421, 490};
    testTemplateBig(graph, Evansville, correctValues);
}

// Tests dijkstra() function using FortWayne as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromFortWayne(const Digraph& graph) {

    int correctValues[verticesBig] = { 405, 1370, 172, 588, 236, 291, 221, 1023, 376, 190, 0, 132, 297, 121, 241, 319, 662, 943, 470, 1155, 1337, 378, 79, 561, 192, 341, 1374, 443};
    testTemplateBig(graph, FortWayne, correctValues);
}

// Tests dijkstra() function using Gary as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromGary(const Digraph& graph) {

    int correctValues[verticesBig] = { 437, 1402, 198, 620, 268, 323, 253, 1055, 408, 277, 132, 0, 329, 153, 273, 351, 694, 975, 502, 1187, 1369, 410, 58, 593, 164, 373, 1406, 475};
    testTemplateBig(graph, Gary, correctValues);
}

// Tests dijkstra() function using GrandRapids as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromGrandRapids(const Digraph& graph) {

    int correctValues[verticesBig] = { 304, 1425, 227, 643, 291, 277, 276, 1078, 147, 344, 297, 329, 0, 176, 56, 374, 717, 998, 525, 1210, 1392, 113, 316, 616, 247, 167, 1429, 342};
    testTemplateBig(graph, GrandRapids, correctValues);
}

// Tests dijkstra() function using Indianapolis as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromIndianapolis(const Digraph& graph) {

    int correctValues[verticesBig] = { 284, 1249, 51, 467, 115, 170, 100, 902, 255, 168, 121, 153, 176, 0, 120, 198, 541, 822, 349, 1034, 1216, 257, 140, 440, 71, 220, 1253, 322};
    testTemplateBig(graph, Indianapolis, correctValues);
}

// Tests dijkstra() function using Kalamazoo as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromKalamazoo(const Digraph& graph) {

    int correctValues[verticesBig] = { 270, 1369, 171, 587, 235, 243, 220, 1022, 135, 288, 241, 273, 56, 120, 0, 318, 661, 942, 469, 1154, 1336, 137, 260, 560, 191, 133, 1373, 308};
    testTemplateBig(graph, Kalamazoo, correctValues);
}

// Tests dijkstra() function using Louisville as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromLouisville(const Digraph& graph) {

    int correctValues[verticesBig] = { 277, 1051, 249, 269, 83, 163, 113, 704, 291, 366, 319, 351, 374, 198, 318, 0, 343, 624, 151, 836, 1018, 375, 338, 242, 269, 233, 1055, 315};
    testTemplateBig(graph, Louisville, correctValues);
}

// Tests dijkstra() function using Milwaukee as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromMilwaukee(const Digraph& graph) {

    int correctValues[verticesBig] = { 620, 758, 592, 74, 426, 506, 456, 361, 634, 709, 662, 694, 717, 541, 661, 343, 0, 332, 494, 493, 690, 718, 681, 336, 612, 576, 759, 658};
    testTemplateBig(graph, Milwaukee, correctValues);
}

// Tests dijkstra() function using Minneapolis as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromMinneapolis(const Digraph& graph) {
    int correctValues[verticesBig] = { 901, 427, 873, 355, 707, 787, 737, 252, 915, 990, 943, 975, 998, 822, 942, 624, 332, 0, 695, 357, 394, 999, 962, 617, 893, 857, 431, 939};
    testTemplateBig(graph, Minneapolis, correctValues);
}

// Tests dijkstra() function using Nashville as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromNashville(const Digraph& graph) {

    int correctValues[verticesBig] = { 428, 1122, 400, 420, 234, 314, 264, 855, 442, 517, 470, 502, 525, 349, 469, 151, 494, 695, 0, 987, 1089, 526, 489, 393, 420, 384, 1126, 466};
    testTemplateBig(graph, Nashville, correctValues);
}

// Tests dijkstra() function using Omaha as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromOmaha(const Digraph& graph) {

    int correctValues[verticesBig] = { 1113, 581, 1085, 567, 919, 999, 949, 132, 1127, 1202, 1155, 1187, 1210, 1034, 1154, 836, 493, 357, 987, 0, 391, 1211, 1174, 829, 1105, 1069, 650, 1151};
    testTemplateBig(graph, Omaha, correctValues);
}

// Tests dijkstra() function using Pierre as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromPierre(const Digraph& graph) {

    int correctValues[verticesBig] = { 1295, 211, 1267, 749, 1101, 1181, 1131, 492, 1309, 1384, 1337, 1369, 1392, 1216, 1336, 1018, 690, 394, 1089, 391, 0, 1393, 1356, 1011, 1287, 1251, 521, 1333};
    testTemplateBig(graph, Pierre, correctValues);
}

// Tests dijkstra() function using Saginaw as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromSaginaw(const Digraph& graph) {

    int correctValues[verticesBig] = { 279, 1426, 308, 644, 292, 252, 262, 1079, 98, 425, 378, 410, 113, 257, 137, 375, 718, 999, 526, 1211, 1393, 0, 397, 617, 328, 142, 1430, 317};
    testTemplateBig(graph, Saginaw, correctValues);
}

// Tests dijkstra() function using SouthBend as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromSouthBend(const Digraph& graph) {

    int correctValues[verticesBig] = { 424, 1389, 191, 607, 255, 310, 240, 1042, 395, 269, 79, 58, 316, 140, 260, 338, 681, 962, 489, 1174, 1356, 397, 0, 580, 196, 360, 1393, 462};
    testTemplateBig(graph, SouthBend, correctValues);
}

// Tests dijkstra() function using SaintLouis as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromSaintLouis(const Digraph& graph) {

    int correctValues[verticesBig] = { 519, 1044, 491, 262, 325, 405, 355, 697, 533, 608, 561, 593, 616, 440, 560, 242, 336, 617, 393, 829, 1011, 617, 580, 0, 511, 475, 1048, 557};
    testTemplateBig(graph, SaintLouis, correctValues);
}

// Tests dijkstra() function using TerreHaute as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromTerreHaute(const Digraph& graph) {

    int correctValues[verticesBig] = { 355, 1320, 58, 538, 186, 241, 171, 973, 326, 113, 192, 164, 247, 71, 191, 269, 612, 893, 420, 1105, 1287, 328, 196, 511, 0, 291, 1324, 393};
    testTemplateBig(graph, TerreHaute, correctValues);
}

// Tests dijkstra() function using Toledo as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromToledo(const Digraph& graph) {

    int correctValues[verticesBig] = { 137, 1284, 271, 502, 150, 110, 120, 937, 58, 388, 341, 373, 167, 220, 133, 233, 576, 857, 384, 1069, 1251, 142, 360, 475, 291, 0, 1288, 175};
    testTemplateBig(graph, Toledo, correctValues);
}

// Tests dijkstra() function using Winnepeg as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromWinnepeg(const Digraph& graph) {

    int correctValues[verticesBig] = { 1332, 369, 1304, 786, 1138, 1218, 1168, 680, 1346, 1421, 1374, 1406, 1429, 1253, 1373, 1055, 759, 431, 1126, 650, 521, 1430, 1393, 1048, 1324, 1288, 0, 1370};
    testTemplateBig(graph, Winnepeg, correctValues);
}

// Tests dijkstra() function using Youngstown as the source
// @param graph [in] Directed graph that stores all of the vertices (cities)
void Test::testDijkstraFromYoungstown(const Digraph& graph) {

    int correctValues[verticesBig] = { 38, 1366, 373, 584, 232, 152, 222, 1019, 233, 490, 443, 475, 342, 322, 308, 315, 658, 939, 466, 1151, 1333, 317, 462, 557, 393, 175, 1370, 0};
    testTemplateBig(graph, Youngstown, correctValues);
}
