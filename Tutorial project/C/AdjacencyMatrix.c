#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of vertices

// Function to initialize the matrix with zeros
void initializeMatrix(int matrix[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0; // Set every cell to 0 (no edges initially)
        }
    }
}

// Function to add an edge to an Undirected Graph
void addEdgeUndirected(int matrix[MAX][MAX], int src, int dest) {
    matrix[src][dest] = 1; // Create edge from source to destination
    matrix[dest][src] = 1; // Create edge from destination to source (symmetric)
}

// Function to add an edge to a Directed Graph
void addEdgeDirected(int matrix[MAX][MAX], int src, int dest) {
    matrix[src][dest] = 1; // Create edge only from source to destination
}

// Function to display the matrix
void displayMatrix(int matrix[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]); // Print the value (0 or 1)
        }
        printf("\n"); // Move to the next row
    }
}

int main() {
    int vertices = 4; // Define number of nodes
    int adjUndirected[MAX][MAX]; // Matrix for undirected graph
    int adjDirected[MAX][MAX];   // Matrix for directed graph

    // --- Undirected Graph Section ---
    printf("Undirected Graph Matrix:\n");
    initializeMatrix(adjUndirected, vertices); // Fill with 0s
    addEdgeUndirected(adjUndirected, 0, 1);    // Edge between 0 and 1
    addEdgeUndirected(adjUndirected, 0, 2);    // Edge between 0 and 2
    addEdgeUndirected(adjUndirected, 1, 3);    // Edge between 1 and 3
    displayMatrix(adjUndirected, vertices);    // Output result

    printf("\n");

    // --- Directed Graph Section ---
    printf("Directed Graph Matrix (0 -> 1, 1 -> 2, 2 -> 0):\n");
    initializeMatrix(adjDirected, vertices);   // Fill with 0s
    addEdgeDirected(adjDirected, 0, 1);        // Only 0 points to 1
    addEdgeDirected(adjDirected, 1, 2);        // Only 1 points to 2
    addEdgeDirected(adjDirected, 2, 0);        // Only 2 points to 0
    displayMatrix(adjDirected, vertices);      // Output result

    return 0;
}