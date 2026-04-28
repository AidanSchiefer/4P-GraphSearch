/*
 * graph.cpp
 *
 * Method definitions for the graph class.
 *
 * Author: Aidan Schiefer
 */

#include "graph.h"
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
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
    //----- Data structure definitions ------

    // Boolean vector that stores if each vertex has been visited
    vector<bool> visited(vertexCount, false);
    // Queue that stores unvisited vertecies
    queue<int> q;
    // Parent vector that stores parent nodes
    vector<int> parent(vertexCount, -1);

    //----- Initial setup ------

    // Set visited at "from" to true
    visited.at(from) = true;
    // Add "from" to the queue
    q.push(from);

    //----- BFS Algorithm -----
    while(!q.empty() && !visited.at(to)){
        // Dequeue the front of the queue into a variable
        int u =  q.front();
        q.pop();

        // For all edges in directed_graph.at(u)
        for(int w: directed_graph.at(u)){
            // If the edge has not been visited, enter the if statement
            if (!visited.at(w)){
                // Add w to the queue
                q.push(w);
                // Set current w as visited
                visited.at(w) = true;
                // w's parent is equal to u
                parent.at(w) = u;
            }
        }
    }

    // List definition
    vector<int> list;

    //----- Shortest path reconstruction -----

    // placeholder to parameter doesn't get modified
    int current = to;
    if (visited.at(current)){
        list.push_back(current);
        while(current != from){
            // current equals its parent
            current = parent.at(current);
            // Add the parent of current to the list 
            list.push_back(current);
        }
    }
    else{
        // No path was found, return the empty list
        return list;
    }

    // Reverse the path list
    reverse(list.begin(), list.end());
    // Return the shortest path as a lis
    return list;
}