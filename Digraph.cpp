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

unsigned int Digraph::noVertices()
{
    // @TODO
    // not sure what this function does, not used in main()

    return -1;
}

unsigned int Digraph::noEdges()
{
    // @TODO
    // not sure what this function does, not used in main()

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


// If there is not already an edge that directly connects
// `source` to `destination`, it is added.
// @param source The index of the source city.
// @param destination The index of the destination city.
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
// `destination`, it is deleted.
// @param source The index of the source city.
// @param destination The index of the destination city.
void Digraph::deleteEdge(int source, int destination)
{
    // check if the edge exists
    if (!isEdge(source, destination))
        return;

    // delete the edge @TODO
    --numberOfEdges;
}

int Digraph::isEdge(int source, int destination)
{
    // @TODO
    // checks if the specified edge exists (need to verify that is the intended functionality)
    return -1;
}

int Digraph::dijkstra(int source, int destination) const
{
    // @TODO
    // finds shortest path from the source to the destination

    return -1;
}
