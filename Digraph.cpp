/*
    @file Digraph.cpp

    Implementation file for directed graph class
*/

#include "Digraph.hpp"

void Digraph::addVertex(string s)
{
    Node* n = new Node(s);
    vertex.push_back(n);
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
    // @TODO
}

void Digraph::addEdge(int source, int dest, int wt)
{
    // @TODO
}

void Digraph::delEdge(int source, int dest)
{
    // @TODO
}

int Digraph::isEdge(int source, int dest)
{
    // @TODO

    return -1;
}

int Digraph::dijkstra(int source, int dest)
{
    // @TODO

    return -1;
}
