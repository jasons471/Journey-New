#include <stdio.h>

#define MAX 5  // Total number of vertices

int adj[MAX][MAX];  // 2D matrix to store connections
int visited[MAX];   // 1 if visited, 0 if not visited
int queue[MAX];     // Array queue for BFS
int front = 0;      // Read position of queue
int rear = 0;       // Write position of queue

int comparisons = 0;  // Count of condition checks
int shifts = 0;       // Count of writes into queue

// Function to add a line (edge) between two nodes
void addEdge(int u, int v) {
    adj[u][v] = 1;  // Connect u to v
    adj[v][u] = 1;  // Connect v to u because it is undirected
}

// Function to print an array: [ 0 1 0 ]
void printArray(int arr[], int size) {
    printf("[ ");  // Print start bracket
    for (int i = 0; i < size; i++) {  // Loop through all items
        printf("%d ", arr[i]);        // Print current item
    }
    printf("]\n"); // Print end bracket
}

// Function to print items waiting in the queue
void printQueue() {
    printf("[ ");  // Print start bracket
    for (int i = front; i < rear; i++) {  // Loop from front up to rear
        printf("%d ", queue[i]);          // Print waiting item
    }
    printf("]\n"); // Print end bracket
}

// Simple Breadth First Search function
void BFS(int start) {
    // Put start node into the queue
    queue[rear] = start;
    rear++;          // Move rear to next empty slot
    shifts++;        // Count this write into queue

    // Mark the start node as visited
    visited[start] = 1;

    printf("\n--- Start BFS ---\n");
    printf("Initial Visited: ");
    printArray(visited, MAX);  // Show visited array
    printf("Initial Queue:   ");
    printQueue();              // Show queue

    int step = 1;  // Step counter

    // While there are still nodes in the queue
    while (front < rear) {
        comparisons++;  // Count queue condition check

        // Remove node from front of queue
        int curr = queue[front];
        front++;  // Move front forward

        printf("\nStep %d: Dequeued node %d\n", step++, curr);

        // Check all potential neighbors
        for (int i = 0; i < MAX; i++) {
            comparisons++;  // Count loop check

            // Check if connection exists and node is not visited yet
            comparisons += 2;  // Count edge check and visited check
            if (adj[curr][i] == 1 && visited[i] == 0) {
                // Add neighbor to queue
                queue[rear] = i;
                rear++;      // Move rear index
                shifts++;    // Count queue write

                // Mark neighbor as visited
                visited[i] = 1;

                printf("  Found neighbor %d -> Added to queue\n", i);
            }
        }

        // Show intermediate arrays after processing this node
        printf("Current Visited: ");
        printArray(visited, MAX);
        printf("Current Queue:   ");
        printQueue();
    }
}

int main() {
    // Add edges to create the graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    // Run BFS starting from node 0
    BFS(0);

    // Display total counts
    printf("\nTotal Comparisons: %d\n", comparisons);
    printf("Total Shifts (Queue Writes): %d\n", shifts);

    return 0;  
}