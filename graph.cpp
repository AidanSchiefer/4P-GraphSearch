/*
 * graph.cpp
 *
 * Method definitions for the graph class.
 *
 * Author: <your name here>
 */

#include "graph.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;


graph::graph(int vertex_count){
    // Store the total vertex count for later use
    vertexCount = vertex_count;
    // Resize the graph's size to the total vertex count
    directed_graph.resize(vertex_count);
}

void graph::add_edge(int from, int to){
    // At the "to" parameter as a neighbor to the vertex at "from"
    directed_graph.at(from).push_back(to);
}

vector<int> graph::find_shortest_path(int from, int to){
    
}