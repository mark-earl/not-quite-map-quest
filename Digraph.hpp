/*
    @file Digraph.cpp

    Interface file for directed graph class
*/

#ifndef DIGRAPH_HPP
#define DIGRAPH_HPP

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

enum Status { NOT_VISITED, VISITED };

class Node {

private:

    // name of the city
    string name;

    // whether the city has been visited or not
    enum Status status;

public:

    // constructor
    Node(string id) {
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
    string getName() const {
        return name;
    }
};

class Digraph {

protected:
    unsigned int numberOfVertices = 0;
    unsigned int numberOfEdges = 0;
    std::vector<Node*> vertex;
    // 2D vector
    std::vector<std::vector<int>> distMatrix;

public:

    void addVertex(string s);
    unsigned int noVertices();
    unsigned int noEdges();
    void resetEdges();
    void addEdge(int source, int dest, int wt);
    void delEdge(int source, int dest);
    int isEdge(int source, int dest);
    int dijkstra(int source, int dest);
};

#endif // DIGRAPH_HPP
