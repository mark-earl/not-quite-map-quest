/*
    @file Digraph.cpp

    Implementation file for directed graph class
*/

#include <string>
#include <limits>
#include "Digraph.hpp"

// 2147483647
const int INFINITY = std::numeric_limits<int>::max();

// Adds the city named `id` to the directed graph
// @param id [in] The name of the city
void Digraph::addVertex(std::string id) {

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

// Resets all edge values to -1
void Digraph::resetEdges() {

    // assign edge values to -1
    for(auto& edge:distMatrix)
        edge.assign(numberOfVertices, -1);

    // set number of edges to 0
    numberOfEdges = 0;
}


// If there is not already an edge that directly connects
// `source` to `destination`, it is added
// @param source The index of the source city
// @param destination The index of the destination city
// @param weight The distance between `source` and `destination`
void Digraph::addEdge(int source, int destination, int weight) {

    // if the edge does not exist
    if (isEdge(source, destination) == -1) {

        // add the edge to the graph
        distMatrix[source][destination] = weight;
        ++numberOfEdges;
    }
}

// If there is an edge that directly connects `source` to
// `destination`, it is deleted
// @param source The index of the source city
// @param destination The index of the destination city
void Digraph::deleteEdge(int source, int destination) {

    // if the edge exists
    if (isEdge(source, destination) != -1) {

        // delete the edge, -1 represents the absence of an edge
        distMatrix[source][destination] = -1;
        --numberOfEdges;
    }
}

// Checks to see if an edge exists that directly connects `source` to `destination`
// @param source The index of the source city
// @param destination The index of the destination city
// @return An integer representing the distance between `source` and `destination`
// @retval -1 An edge DOES NOT exist that directly connects `source` to `destination`
int Digraph::isEdge (int source, int destination) const
{
    if (distMatrix[source][destination] == 0)
        return -1;
    return distMatrix[source][destination];
}

// Compute shortest path distances from `source` to `destination`
int Digraph::dijkstra(int source, int destination) const
{
    // holds min distance to each vertex from source
    std::vector<int> dist(numberOfVertices, INFINITY);

    // the distance from the source, to the source, is 0
    dist[source] = 0;

    // iterate over all the vertices
    for (auto vertex:vertices) {
        // Find the closest vertex that has not been visited
        int u = minVertexIndex(dist);
        vertices[u]->setStatus(Status::VISITED);

        // Check if we have reached the destination vertex
        if (u == destination) {
            break;
        }

        // Update the distances of all reachable neighbors of u
        for (int v = 0; v < numberOfVertices; ++v) {

            // If u and v are adjacent
            if (isEdge(u, v) != -1 && vertices[v]->getStatus() == Status::NOT_VISITED) {
                // Calculate the new distance from source to v through u
                int alt = dist[u] + distMatrix[u][v];
                // If the new distance is shorter than the current distance
                if (alt < dist[v]) {
                    // Update the distance to v
                    dist[v] = alt;
                }
            }
        }
    }

    // Return the distance to the destination vertex if it exists, otherwise return INFINITY
    return dist[destination];
}

int Digraph::minVertexIndex(const std::vector<int>& dist) const {
    // Initialize min value
    int minDist = INFINITY;
    int minVertexIndex = -1;

    // Iterate over all vertices
    for (int v = 0; v < numberOfVertices; ++v) {

        // If v has not been visited and its distance is less than or equal to the minimum distance seen so far
        if (vertices[v]->getStatus() == Status::NOT_VISITED && dist[v] <= minDist) {

            // Update the minimum distance
            minDist = dist[v];

            // Update the index of the vertex with the minimum distance
            minVertexIndex = v;
        }
    }

    // Return the index of the vertex with the minimum distance
    return minVertexIndex;
}
