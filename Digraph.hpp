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

enum Status { NOT_VISITED, VISITED };

class Node {

private:

    // name of the city
    std::string name;

    // whether the city has been visited or not
    enum Status status;

public:

    // constructor
    Node(std::string id) {
        name = id;
        status = NOT_VISITED;
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

protected:
    unsigned int numberOfVertices = 0;
    unsigned int numberOfEdges = 0;
    std::vector<Node*> vertices;
    // 2D vector
    std::vector<std::vector<int>> distMatrix;

public:

    void addVertex(std::string s);
    unsigned int noVertices();
    unsigned int noEdges();
    void resetEdges();
    void addEdge(int source, int destination, int weight);
    void deleteEdge(int source, int destination);
    int isEdge(int source, int destination);
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
