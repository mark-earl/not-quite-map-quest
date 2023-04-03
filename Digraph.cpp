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
    // vector to store the minimum distance from the source vertex to each vertex
    std::vector<int> dist(numberOfVertices, INFINITY);

    // set the distance from the source vertex to itself to 0
    dist[source] = 0;

    // vector to store whether each vertex has been visited or not
    std::vector<bool> visited(numberOfVertices, false);

    // loop through all vertices
    for (unsigned int i = 0; i < numberOfVertices; ++i) {

        // get the index of the vertex with the minimum distance from the source
        int minVertexIndex = minVertex(dist, visited);

        // mark the vertex as visited
        visited[minVertexIndex] = true;

        // loop through all neighbors of the current vertex
        for (unsigned int j = 0; j < numberOfVertices; ++j) {

            // if there is an edge between the current vertex and its neighbor
            if (isEdge(minVertexIndex, j) != -1) {

                // calculate the distance to the neighbor through the current vertex
                int alt = dist[minVertexIndex] + isEdge(minVertexIndex, j);

                // if the new distance is shorter than the current distance
                if (alt < dist[j]) {

                    // update the distance to the neighbor
                    dist[j] = alt;
                }
            }
        }
    }

    // return the minimum distance to the destination vertex
    return dist[destination];
}

int Digraph::minVertex(const std::vector<int>& dist, const std::vector<bool>& visited) const {
    // initialize the minimum distance to infinity
    int minDist = INFINITY;

    // initialize the index of the minimum vertex to -1
    int minIndex = -1;

    // loop through all vertices
    for (int i = 0; i < numberOfVertices; ++i) {

        // if the vertex has not been visited and its distance from the source is less than the current minimum distance
        if (!visited[i] && dist[i] <= minDist) {

            // set the minimum distance to the distance of the current vertex from the source
            minDist = dist[i];

            // set the index of the minimum vertex to the current vertex
            minIndex = i;
        }
    }

    // return the index of the vertex with the minimum distance from the source
    return minIndex;
}
