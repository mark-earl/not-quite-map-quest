/*
    @file TestSuite.cpp

    Implementation file for the test suite on dijkstra's algorithm
*/

#include "test_suite.hpp"
#include "Digraph.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

// number of vertices in nqmq.dat and nqmqBig.dat, respectively
const int VERTICES = 8;
const int VERTICES_BIG = 28;

// Map the city indexes to their names
std::map<int, std::string> CITIES_MAP {

    // nqmq.dat
    {0, "Atlanta_GA"},
    {1, "Boston_MA"},
    {2, "Chicago_IL"},
    {3, "Denver_CO"},
    {4, "Los_Angeles_CA"},
    {5, "Miami_FL"},
    {6, "New_York_NY"},
    {7, "San_Francisco_CA"},

    // nqmqBig.dat
    {8, "Akron"},
    {9, "Bismarck"},
    {10, "Bloomington"},
    {11, "Chicago"},
    {12, "Cincinnati"},
    {13, "Columbus"},
    {14, "Dayton"},
    {15, "Des Moines"},
    {16, "Detroit"},
    {17, "Evansville"},
    {18, "Fort Wayne"},
    {19, "Gary"},
    {20, "Grand Rapids"},
    {21, "Indianapolis"},
    {22, "Kalamazoo"},
    {23, "Louisville"},
    {24, "Milwaukee"},
    {25, "Minneapolis"},
    {26, "Nashville"},
    {27, "Omaha"},
    {28, "Pierre"},
    {29, "Saginaw"},
    {30, "South Bend"},
    {31, "Saint Louis"},
    {32, "Terre Haute"},
    {33, "Toledo"},
    {34, "Winnepeg"},
    {35, "Youngstown"}
};

// Helper function. Tests the dijkstra() function from `source` to all cities in `graph`
// @param graph [in] Directed graph that stores all of the vertices (cities)
// @param source [in] The specified "starting point"
// @param correctValues [in] An array that holds the correct values for output of dijkstra's algorithm
// @param bigData [in] Flag indicating whether we are using the big data file or not
void testTemplate(const Digraph& graph, int source, const std::vector<int>& correctValues, bool fullReport, bool bigData, bool& passedAllTests) {

    // formatting constants
    const int cityWidth = 36;
    const int distWidth = 10;
    const int passedWidth = 8;

    // offset the index appropriately
    const int indexOffset = bigData ? VERTICES : 0;

    // test description
    std::string startingCity = CITIES_MAP[source + indexOffset];
    std::cout << "## TEST " << source + 1 << ((source + 1 > 9) ? "." : ". ") << " Starting from " << std::setw(20) << std::left << startingCity;

    // table columns
    if (fullReport) {
        std::cout << "\n| Route                              | Distance | Passed |\n";
        std::cout <<   "|:-----------------------------------|---------:|:------:|\n";
    }

    // flag for current test
    bool passed = true;

    // iterate through the cities
    for (int CITY = 0; CITY < (bigData ? VERTICES_BIG : VERTICES); ++CITY) {

        // get route and distance
        std::string route = CITIES_MAP[source + indexOffset] + " -> " + CITIES_MAP[CITY + indexOffset];
        int dist = graph.dijkstra(source , CITY);

        // output route and distance
        if (fullReport) {
            std::cout << '|' << std::setw(cityWidth) << std::left << route;
            std::cout << '|' << std::setw(distWidth) << std::right << dist << '|';
        }

        // get passed condition (OK or FAIL)
        std::string passedMessage = "OK";

        if (dist != correctValues[CITY]) {
            passedMessage = "FAIL";
            passed = false;
        }

        // output passed condition
        if (fullReport)
            std::cout << std::setw(passedWidth) << std::right << passedMessage << "|\n";
    }

    // get test summary
    std::string passedMessage = "Passed";

    if (!passed) {
        passedMessage = "FAILED";
        passedAllTests = false;
    }

    // output test summary
    if (fullReport)
        std::cout << "\nTEST " << source + 1 << " - " << passedMessage << "\n\n";
    else
        std::cout << passedMessage << "\n";

}

// Tests dijkstra's algorithm
// @param graph [in] The graph represented as an adjacency matrix
// @param fullReport [in] Determines the output format [Y/N]
// @param bigData [in] Determines the input for the algorithm (false by default)
void testSuite(const Digraph& graph, bool fullReport, bool bigData) {

    // holds the correct values for each test
    std::vector<std::vector<int>> correctDistances;

    // nqmqBig.dat
    if (bigData) correctDistances = {
        { 0, 1328, 335, 546, 194, 114, 184, 981, 195, 452, 405, 437, 304, 284, 270, 277, 620, 901, 428, 1113, 1295, 279, 424, 519, 355, 137, 1332, 38},                     // Akron as the source
        { 1328, 0, 1300, 782, 1134, 1214, 1164, 670, 1342, 1417, 1370, 1402, 1425, 1249, 1369, 1051, 758, 427, 1122, 581, 211, 1426, 1389, 1044, 1320, 1284, 369, 1366},    // Bismarck as the source
        { 335, 1300, 0, 518, 166, 221, 151, 953, 306, 119, 172, 198, 227, 51, 171, 249, 592, 873, 400, 1085, 1267, 308, 191, 491, 58, 271, 1304, 373},                      // Bloomington as the source
        { 546, 782, 518, 0, 352, 432, 382, 435, 560, 635, 588, 620, 643, 467, 587, 269, 74, 355, 420, 567, 749, 644, 607, 262, 538, 502, 786, 584},                         // Chicago as the source
        { 194, 1134, 166, 352, 0, 80, 30, 787, 208, 283, 236, 268, 291, 115, 235, 83, 426, 707, 234, 919, 1101, 292, 255, 325, 186, 150, 1138, 232},                        // Cincinnati as the source
        { 114, 1214, 221, 432, 80, 0, 70, 867, 168, 338, 291, 323, 277, 170, 243, 163, 506, 787, 314, 999, 1181, 252, 310, 405, 241, 110, 1218, 152},                       // Columbus as the source
        { 184, 1164, 151, 382, 30, 70, 0, 817, 178, 268, 221, 253, 276, 100, 220, 113, 456, 737, 264, 949, 1131, 262, 240, 355, 171, 120, 1168, 222},                       // Dayton as the source
        { 981, 670, 953, 435, 787, 867, 817, 0, 995, 1070, 1023, 1055, 1078, 902, 1022, 704, 361, 252, 855, 132, 492, 1079, 1042, 697, 973, 937, 680, 1019},                // DesMoines as the source
        { 195, 1342, 306, 560, 208, 168, 178, 995, 0, 423, 376, 408, 147, 255, 135, 291, 634, 915, 442, 1127, 1309, 98, 395, 533, 326, 58, 1346, 233},                      // Detroit as the source
        { 452, 1417, 119, 635, 283, 338, 268, 1070, 423, 0, 190, 277, 344, 168, 288, 366, 709, 990, 517, 1202, 1384, 425, 269, 608, 113, 388, 1421, 490},                   // Evansville as the source
        { 405, 1370, 172, 588, 236, 291, 221, 1023, 376, 190, 0, 132, 297, 121, 241, 319, 662, 943, 470, 1155, 1337, 378, 79, 561, 192, 341, 1374, 443},                    // FortWayne as the source
        { 437, 1402, 198, 620, 268, 323, 253, 1055, 408, 277, 132, 0, 329, 153, 273, 351, 694, 975, 502, 1187, 1369, 410, 58, 593, 164, 373, 1406, 475},                    // Gary as the source
        { 304, 1425, 227, 643, 291, 277, 276, 1078, 147, 344, 297, 329, 0, 176, 56, 374, 717, 998, 525, 1210, 1392, 113, 316, 616, 247, 167, 1429, 342},                    // GrandRapids as the source
        { 284, 1249, 51, 467, 115, 170, 100, 902, 255, 168, 121, 153, 176, 0, 120, 198, 541, 822, 349, 1034, 1216, 257, 140, 440, 71, 220, 1253, 322},                      // Indianapolis as the source
        { 270, 1369, 171, 587, 235, 243, 220, 1022, 135, 288, 241, 273, 56, 120, 0, 318, 661, 942, 469, 1154, 1336, 137, 260, 560, 191, 133, 1373, 308},                    // Kalamazoo as the source
        { 277, 1051, 249, 269, 83, 163, 113, 704, 291, 366, 319, 351, 374, 198, 318, 0, 343, 624, 151, 836, 1018, 375, 338, 242, 269, 233, 1055, 315},                      // Louisville as the source
        { 620, 758, 592, 74, 426, 506, 456, 361, 634, 709, 662, 694, 717, 541, 661, 343, 0, 332, 494, 493, 690, 718, 681, 336, 612, 576, 759, 658},                         // Milwaukee as the source
        { 901, 427, 873, 355, 707, 787, 737, 252, 915, 990, 943, 975, 998, 822, 942, 624, 332, 0, 695, 357, 394, 999, 962, 617, 893, 857, 431, 939},                        // Minneapolis as the source
        { 428, 1122, 400, 420, 234, 314, 264, 855, 442, 517, 470, 502, 525, 349, 469, 151, 494, 695, 0, 987, 1089, 526, 489, 393, 420, 384, 1126, 466},                     // Nashville as the source
        { 1113, 581, 1085, 567, 919, 999, 949, 132, 1127, 1202, 1155, 1187, 1210, 1034, 1154, 836, 493, 357, 987, 0, 391, 1211, 1174, 829, 1105, 1069, 650, 1151},          // Omaha as the source
        { 1295, 211, 1267, 749, 1101, 1181, 1131, 492, 1309, 1384, 1337, 1369, 1392, 1216, 1336, 1018, 690, 394, 1089, 391, 0, 1393, 1356, 1011, 1287, 1251, 521, 1333},    // Pierre as the source
        { 279, 1426, 308, 644, 292, 252, 262, 1079, 98, 425, 378, 410, 113, 257, 137, 375, 718, 999, 526, 1211, 1393, 0, 397, 617, 328, 142, 1430, 317},                    // Saginaw as the source
        { 424, 1389, 191, 607, 255, 310, 240, 1042, 395, 269, 79, 58, 316, 140, 260, 338, 681, 962, 489, 1174, 1356, 397, 0, 580, 196, 360, 1393, 462},                     // SouthBend as the source
        { 519, 1044, 491, 262, 325, 405, 355, 697, 533, 608, 561, 593, 616, 440, 560, 242, 336, 617, 393, 829, 1011, 617, 580, 0, 511, 475, 1048, 557},                     // SaintLouis as the source
        { 355, 1320, 58, 538, 186, 241, 171, 973, 326, 113, 192, 164, 247, 71, 191, 269, 612, 893, 420, 1105, 1287, 328, 196, 511, 0, 291, 1324, 393},                      // TerreHaute as the source
        { 137, 1284, 271, 502, 150, 110, 120, 937, 58, 388, 341, 373, 167, 220, 133, 233, 576, 857, 384, 1069, 1251, 142, 360, 475, 291, 0, 1288, 175},                     // Toledo as the source
        { 1332, 369, 1304, 786, 1138, 1218, 1168, 680, 1346, 1421, 1374, 1406, 1429, 1253, 1373, 1055, 759, 431, 1126, 650, 521, 1430, 1393, 1048, 1324, 1288, 0, 1370},    // Winnepeg as the source
        { 38, 1366, 373, 584, 232, 152, 222, 1019, 233, 490, 443, 475, 342, 322, 308, 315, 658, 939, 466, 1151, 1333, 317, 462, 557, 393, 175, 1370, 0}                     // Youngstown as the source
    };

    // nqmq.dat
    else correctDistances = {
    { 0, 951, 606, 1514, 2348, 595, 760, 2461 },    // Atlanta_GA as the source
    { 951, 0, 860, 1768, 2602, 1281, 191, 2715 },   // Boston_MA as the source
    { 606, 860, 0, 908, 1742, 1201, 722, 1855 },    // Chicago_IL as the source
    { 1514, 1768, 908, 0, 834, 2109, 1630, 957 },   // Denver_CO as the source
    { 2348, 2602, 1742, 834, 0, 2943, 2451, 349 },  // Los_Angeles_CA as the source
    { 595, 1281, 1201, 2109, 2943, 0, 1090, 3056 }, // Miami_FL as the source
    { 760, 191, 722, 1630, 2451, 1090, 0, 2534 },   // New_York_NY as the source
    { 2461, 2715, 1855, 957, 349, 3056, 2534, 0 }   // San_Francisco_CA as the source
    };

    // test all cities
    bool passedAllTests = true;
    for(int city = 0; city < (bigData ? VERTICES_BIG : VERTICES); ++city)
        testTemplate(graph, city, correctDistances[city], fullReport, bigData, passedAllTests);

    // let client know all tests passed
    if (passedAllTests)
        std::cout << "## All Tests Passed!\n\n";

}
