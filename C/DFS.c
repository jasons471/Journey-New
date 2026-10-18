#include <stdio.h>    
#define MAX_NODES 5   // Defines the maximum number of nodes in the graph

// Recursive function to perform Depth-First Search defined before main
void dfs(int currentNode, int visited[MAX_NODES], int graph[MAX_NODES][MAX_NODES]) {
    // Flag the current node as visited using integer 1
    visited[currentNode] = 1;

    // Output the current node value
    printf("%d ", currentNode);

    // Iterate through all possible neighboring nodes
    for (int neighbor = 0; neighbor < MAX_NODES; neighbor++) {
        // If an edge exists (value 1) and the neighbor is unvisited (value 0)
        if (graph[currentNode][neighbor] == 1 && visited[neighbor] == 0) {
            // Recursively visit the adjacent node
            dfs(neighbor, visited, graph);
        }
    }
}

int main() {
    // Adjacency matrix representation of an undirected graph with 5 nodes (0 to 4)
    // graph[u][v] = 1 indicates an edge exists between node u and node v
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0},  // Node 0 connects to Node 1 and Node 2
        {1, 0, 0, 1, 1},  // Node 1 connects to Node 0, Node 3, and Node 4
        {1, 0, 0, 0, 0},  // Node 2 connects to Node 0
        {0, 1, 0, 0, 0},  // Node 3 connects to Node 1
        {0, 1, 0, 0, 0}   // Node 4 connects to Node 1
    };

    // Integer array used as visit flags (0 = unvisited, 1 = visited)
    int visited[MAX_NODES] = {0};

    // Print label for the output sequence
    printf("DFS Traversal starting from node 0:\n");

    // Initiate DFS starting from node index 0
    dfs(0, visited, graph);

    printf("\n");

    return 0;
}

