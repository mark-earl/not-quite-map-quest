/*
    @file Digraph.cpp

    Implementation file for directed graph class
*/

#include <string>
#include "Digraph.hpp"

// Adds the city named `id` to the directed graph
// @param id [in] The name of the city
void Digraph::addVertex(std::string id)
{
    // add the new city
    Node* newNode = new Node(id);
    vertices.push_back(newNode);
    ++numberOfVertices;

    // resize first dimension
    distMatrix.resize(numberOfVertices);

    // resize second dimension
    for (auto& edge : distMatrix) {
        edge.resize(numberOfVertices);
    }
}

// Returns the number of vertices
// @stereotype get
unsigned int Digraph::getNumberOfVertices() const { return numberOfVertices; }

// Returns the number of edges
// @stereotype get
unsigned int Digraph::getNumberOfEdges() const { return numberOfEdges; }

// Clears all of the edge vectors by setting them as empty
void Digraph::resetEdges()
{
    // clear every edge (empty vectors)
    for(auto& edge:distMatrix)
        edge.clear();

    // set number of edges to 0
    numberOfEdges = 0;
}


// If there is not already an edge that directly connects
// `source` to `destination`, it is added
// @param source The index of the source city
// @param destination The index of the destination city
// @param weight The distance between `source` and `destination`
void Digraph::addEdge(int source, int destination, int weight)
{
    // check if the edge exists
    if (isEdge(source, destination))
        return;

    // add the edge @TODO
    ++numberOfEdges;
}

// If there is an edge that directly connects `source` to
// `destination`, it is deleted
// @param source The index of the source city
// @param destination The index of the destination city
void Digraph::deleteEdge(int source, int destination)
{
    // check if the edge exists
    if (!isEdge(source, destination))
        return;

    // delete the edge @TODO
    --numberOfEdges;
}

// Checks to see if an edge exists that directly connects `source` to `destination`
// @param source The index of the source city
// @param destination The index of the destination city
// @retval true An edge exists that directly connects `source` to `destination`
// @retval false An edge DOES NOT exist that directly connects `source` to `destination`
bool Digraph::isEdge (int source, int destination) const
{
    // @TODO checks if the specified edge exists
    return true;
    // @TODO other wise, return false
    return false;
}

// If an edge exists that directly connects `source` to `destination`, return its weight
// @return The distance (weight) between `source` and `distance`
// @retval -1 The specified edge from `source` to `destination` DOES NOT exist.
int Digraph::getEdgeWeight(int source, int destination) const {

    if (!isEdge(source, destination)) {
        return -1;
    }

    // @TODO calculate edge weight
    return 123456789;
}

int Digraph::dijkstra(int source, int destination) const
{
    // @TODO find shortest path from the source index to the destination index

    return -1;
}
