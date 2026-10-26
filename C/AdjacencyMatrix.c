#include <stdio.h>
// Define a constant for the maximum capacity of the matrix grid
#define MAX 10

// Function to set all entries in the matrix to 0, representing no edges
void initializeMatrix(int matrix[MAX][MAX], int vertices) {
    // Outer loop runs through each row corresponding to a source vertex
    for (int i = 0; i < vertices; i++) {
        // Inner loop runs through each column corresponding to a destination vertex
        for (int j = 0; j < vertices; j++) {
            // Set cell (i, j) to 0, indicating no connection exists initially
            matrix[i][j] = 0;
        }
    }
}

// Function to insert an undirected edge between two vertices
void addEdgeUndirected(int matrix[MAX][MAX], int src, int dest) {
    // Mark an edge going from src to dest by assigning 1
    matrix[src][dest] = 1;
    // Mark the reverse edge from dest to src to keep it bidirectional/symmetric
    matrix[dest][src] = 1;
}

// Function to insert a directed edge from a source vertex to a destination vertex
void addEdgeDirected(int matrix[MAX][MAX], int src, int dest) {
    // Mark an edge only in the direction from src to dest[cite: 1]
    matrix[src][dest] = 1;
}

// Function to print the entire adjacency matrix row by row
void displayMatrix(int matrix[MAX][MAX], int vertices) {
    // Loop through each row of the matrix
    for (int i = 0; i < vertices; i++) {
        // Loop through each column of the current row
        for (int j = 0; j < vertices; j++) {
            // Print the current cell value 
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Set the number of graph vertices to 4 (labeled 0, 1, 2, 3)
    int vertices = 4;

    // Declare a 2D array of size MAX x MAX for the undirected graph
    int adjUndirected[MAX][MAX];

    // Declare a 2D array of size MAX x MAX for the directed graph
    int adjDirected[MAX][MAX];

    printf("Undirected Graph Matrix:\n");

    // Initialize all cells within the 4x4 region of the undirected matrix to 0
    initializeMatrix(adjUndirected, vertices);

    // Add an undirected edge between vertex 0 and vertex 1
    addEdgeUndirected(adjUndirected, 0, 1);

    // Add an undirected edge between vertex 0 and vertex 2
    addEdgeUndirected(adjUndirected, 0, 2);

    // Add an undirected edge between vertex 1 and vertex 3
    addEdgeUndirected(adjUndirected, 1, 3);

    // Print the completed undirected adjacency matrix
    displayMatrix(adjUndirected, vertices);

    printf("\n");

    // Print a header label detailing the directed graph edges
    printf("Directed Graph Matrix (0 -> 1, 1 -> 2, 2 -> 0):\n");

    // Initialize all cells within the 4x4 region of the directed matrix to 0
    initializeMatrix(adjDirected, vertices);

    // Add a one-way directed edge from vertex 0 to vertex 1
    addEdgeDirected(adjDirected, 0, 1);

    // Add a one-way directed edge from vertex 1 to vertex 2
    addEdgeDirected(adjDirected, 1, 2);

    // Add a one-way directed edge from vertex 2 to vertex 0
    addEdgeDirected(adjDirected, 2, 0);

    displayMatrix(adjDirected, vertices);

    return 0;
}