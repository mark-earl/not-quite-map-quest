/*
    @file Digraph.cpp

    Interface file for directed graph class
*/

#ifndef DIGRAPH_HPP
#define DIGRAPH_HPP

#include <string>
#include <vector>

// -----------------------------------DELETE EVENTUALLY
#include <iostream>
// -----------------------------------DELETE EVENTUALLY

// Enumerated type to help keep track of wether a city has
// been visited or not
enum Status { NOT_VISITED, VISITED };

// Helper class, represents nodes on a directional graph.
// In our case, each node is a city
class Node {

private:

    // name of the city
    std::string name;

    // whether the city has been visited or not
    // NOT_VISITED or VISITED
    enum Status status;

public:

    // constructor
    Node(std::string cityName) {
        name = cityName;
        status = Status::NOT_VISITED;
    }

    // @stereotype get
    enum Status getStatus() const {
        return status;
    }

    // @stereotype set
    void setStatus(enum Status st) {
        status = st;
    }

    // @stereotype get
    std::string getName() const {
        return name;
    }
};

class Digraph {

private:

    // number of vertices (cities) in the graph (map)
    unsigned int numberOfVertices = 0;

    // number of edges (routes) in the graph (map)
    unsigned int numberOfEdges = 0;

    // vector of pointers to nodes (cities)
    std::vector<Node*> vertices;

    /*
        adjacency matrix for storing the directed graph

        something like this:

           0  1  2  3 . . .
        0  0  1  0  0 . . .
        1  1  0  0  1 . . .
        2  0  0  0  0 . . .
        3  0  1  0  0 . . .
        .  .  .  .  .
        .  .  .  .  .
        .  .  .  .  .

        the top row of indices is the first dimension
        the left colum of indices is the second dimension

        note that for each route, there is a path to and from
        the source and destination
    */
    std::vector<std::vector<int>> distMatrix;

public:

    void addVertex(std::string s);
    unsigned int getNumberOfVertices() const;
    unsigned int getNumberOfEdges() const;
    void resetEdges();
    void addEdge(int source, int destination, int weight);
    void deleteEdge(int source, int destination);
    bool isEdge(int source, int destination) const;
    int getEdgeWeight(int source, int destination) const;
    int dijkstra(int source, int destination) const;

    // -----------------------------------DELETE EVENTUALLY
    // for debugging
    void display() {
        for (auto edge:distMatrix) {
            for(auto city:edge) {
                std::cout << city << ", ";
            }
            std::cout << std::endl;
        }
    }

    void setGarbage() {
        distMatrix =
        {
            {0, 1, 2, 3, 4, 5, 6, 7},
            {0, 1, 2, 3, 4, 5, 6, 7},
            {0, 1, 2, 3, 4, 5, 6, 7},
            {0, 1, 2, 3, 4, 5, 6, 7},
            {0, 1, 2, 3, 4, 5, 6, 7},
            {0, 1, 2, 3, 4, 5, 6, 7},
            {0, 1, 2, 3, 4, 5, 6, 7},
            {0, 1, 2, 3, 4, 5, 6, 7}
        };
    }
    // -----------------------------------DELETE EVENTUALLY
};

#endif // DIGRAPH_HPP
