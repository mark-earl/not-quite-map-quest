/*
    @file Digraph.cpp

    Implementation file for directed graph class
*/

#include "Digraph.hpp"

// @param id [in] The name of the city
void Digraph::addVertex(string id)
{
    Node* n = new Node(id);
    vertices.push_back(n);
    numberOfVertices++;
    distMatrix.resize(numberOfVertices);

    for (int i = 0; i < numberOfVertices; i++) {
        distMatrix[i].resize(numberOfVertices);
    }
}

unsigned int Digraph::noVertices()
{
    // @TODO

    return -1;
}

unsigned int Digraph::noEdges()
{
    // @TODO

    return -1;
}

void Digraph::resetEdges()
{
    // clear every edge (empty vectors)
    for(auto& edge:distMatrix)
        edge.clear();

    // set number of edges to 0
    numberOfEdges = 0;
}

void Digraph::addEdge(int source, int destination, int weight)
{
    // @TODO
}

void Digraph::delEdge(int source, int destination)
{
    // @TODO
}

int Digraph::isEdge(int source, int destination)
{
    // @TODO

    return -1;
}

int Digraph::dijkstra(int source, int destination)
{
    // @TODO

    return -1;
}
