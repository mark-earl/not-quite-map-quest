/*
    @file Digraph.cpp

    Interface file for directed graph class
*/

#ifndef DIGRAPH_HPP
#define DIGRAPH_HPP

#include <string>
#include <vector>

// keep track of wether a city has been visited or not
enum Status { NOT_VISITED, VISITED };

// Helper class, represents nodes on a graph.
// In our case, each node is a city
class Node {

private:

    // name of the city
    std::string name;

    // whether the city has been visited or not
    // NOT_VISITED or VISITED
    enum Status status;

public:

    // Constructor. Marks node as not visited and assigns them a name
    // @param cityName [in] The name of the city
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
    int numberOfVertices = 0;

    // number of edges (routes) in the graph (map)
    int numberOfEdges = 0;

    // vector of pointers to nodes (cities)
    std::vector<Node*> vertices;

    // adjacency matrix for storing the directed graph
    // the values are weights(distances)
    std::vector<std::vector<int>> distMatrix;

public:

    // Returns the number of vertices
    // @stereotype get
    int getNumberOfVertices() const;

    // Returns the number of edges
    // @stereotype get
    int getNumberOfEdges() const;

    // Returns the vertex at index `i`
    // @param i [in] The index of the vertex
    Node* getVertex(int i) const;

    // Adds the city named `cityName` to the directed graph
    // @param cityName [in] The name of the city
    void addVertex(std::string cityName);

    // Resets all edge values to -1, indicating a complete absence of edges
    void resetEdges();

    // If there is not already an edge that directly connects
    // `source` to `destination`, it is added
    // @param source The index of the source city
    // @param destination The index of the destination city
    // @param weight The distance between `source` and `destination`
    void addEdge(int source, int destination, int weight);

    // If there is an edge that directly connects `source` to
    // `destination`, it is deleted
    // @param source The index of the source city
    // @param destination The index of the destination city
    void deleteEdge(int source, int destination);

    // Checks to see if an edge exists that directly connects `source` to `destination`
    // @param source The index of the source city
    // @param destination The index of the destination city
    // @return An integer representing the distance between `source` and `destination`
    // @retval -1 An edge DOES NOT exist that directly connects `source` to `destination`
    int isEdge(int source, int destination) const;

    // Compute shortest path distances from `source` to `destination`
    // @param `source` The index of the source city.
    // @param `destination` The index of the destination city.
    // @returns The distance between source and destination
    int dijkstra(int source, int destination) const;

    // Destructor, Frees all allocated memory
    ~Digraph();

private:

    // Returns the vertex with the minimum distance
    // @param dist [in] The vector holding the distances to all the cities from a single-source
    // @returns The index of the vertex with the minimum distance
    int minVertex(const std::vector<int>& dist) const;

};

#endif // DIGRAPH_HPP
