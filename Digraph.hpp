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

    // adjacency matrix for storing the directed graph
    // the values are weights(distances)
    std::vector<std::vector<int>> distMatrix;

public:

    void addVertex(std::string s);
    unsigned int getNumberOfVertices() const;
    unsigned int getNumberOfEdges() const;
    void resetEdges();
    void addEdge(int source, int destination, int weight);
    void deleteEdge(int source, int destination);
    int isEdge(int source, int destination) const;
    int dijkstra(int source, int destination) const;
    Node* getVertex(int i) const { return vertices[i]; }

    // -----------------------------------DELETE EVENTUALLY
    // for debugging
    void display() const {
        for (auto edge:distMatrix) {
            for(auto city:edge) {
                std::cout << city << '\t';
            }
            std::cout << "\n\n\n";
        }
    }
    void displayVertices() const {
        std::cout << "Vertices:\n";
        for (auto vertex:vertices) {
            std::cout << vertex->getName() << ", ";

            if (vertex->getStatus() == 0)
                std::cout << "NOT_VISITED";
            else if (vertex->getStatus() == 1)
                std::cout << "VISITED";

            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void displayDijkstra() const {
        for (int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                std::cout << dijkstra(i, j) << ", ";
            }
            std::cout << "";
        }
    }
    // -----------------------------------DELETE EVENTUALLY

private:

    int minVertex(const std::vector<int>& dist, const std::vector<bool>& visited) const;

};

#endif // DIGRAPH_HPP
