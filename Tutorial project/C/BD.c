#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Graph structure using an adjacency matrix
struct Graph {
    int vertices;
    int adjMatrix[MAX][MAX];
    int visited[MAX];
};

// Queue for BFS implementation
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Function to initialize the graph
void initGraph(struct Graph* g, int v) {
    g->vertices = v;
    for (int i = 0; i < v; i++) {
        g->visited[i] = 0;
        for (int j = 0; j < v; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge
void addEdge(struct Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // For undirected graph
}

// Breadth First Search (BFS) Traversal
void BFS(struct Graph* g, int startNode) {
    for (int i = 0; i < g->vertices; i++) g->visited[i] = 0; // Reset visited

    enqueue(startNode);
    g->visited[startNode] = 1;

    printf("BFS Traversal: ");
    while (front <= rear && front != -1) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[current][i] == 1 && !g->visited[i]) {
                enqueue(i);
                g->visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Depth First Search (DFS) Traversal using Recursion
void DFS(struct Graph* g, int vertex) {
    g->visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !g->visited[i]) {
            DFS(g, i);
        }
    }
}

int main() {
    struct Graph g;
    int v = 5; // Number of vertices

    initGraph(&g, v);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);

    // Perform BFS
    BFS(&g, 0);

    // Reset visited for DFS
    for (int i = 0; i < v; i++) g.visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(&g, 0);
    printf("\n");

    return 0;
}