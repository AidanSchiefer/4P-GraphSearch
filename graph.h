/*
 * graph.h
 *
 * Declaration of the graph class.
 * 
 * Author: Aidan Schiefer
 */

#ifndef _GRAPH_BFS_H
#define _GRAPH_BFS_H

#include <vector>

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead put them at the beginning of class or function definitions
 * (as demonstrated below).
 */

class graph {
public:
    graph(int vertex_count);
    void add_edge(int from, int to);
	std::vector<int> find_shortest_path(int from, int to);

private:
    // Data structure to represent our graph
    std::vector<std::vector<int>> directed_graph;
    // Tracker for total vertex count for DFS implementation
    int vertexCount;
};

#endif
