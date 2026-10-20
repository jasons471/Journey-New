#include <stdio.h>
#include <string.h>

/* Number of villages in the mystical realm */
#define N 9

/* Global variables to store the state of the world */
char village[N][50];      /* Array to store 9 village names */
int graph[N][N];         /* Adjacency matrix: 1 if road exists, 0 otherwise */
char route[N][N][50];    /* Stores the road name for each village */

/* * Task: Removes the trailing newline (\n) from a string.
 * This is necessary because fgets() includes the 'Enter' key press in the string.
 */
void removeNewline(char str[]) {
    size_t len = strlen(str); /* Calculate length using size_t (standard for sizes) */
    
    /* Condition: Only replace if string isn't empty and the last char is a newline */
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0'; /* Replace '\n' with null terminator to end string early */
}

/* * Task: Finds the index number (0-8) of a village by its name.
 */
int getIndex(char name[]) {
    /* Loop through all possible village slots */
    for (int i = 0; i < N; i++) {
        /* Condition: Check if the input name matches the stored village name */
        if (strcmp(village[i], name) == 0)
            return i; /* Found the village, return its index */
    }
    return -1; /* Return -1 if no match is found after checking all villages */
}

/* * Task: Creates a two-way connection and assigns a road name.
 */
void addRoute(int u, int v, char name[]) {
    graph[u][v] = 1; /* Mark road from village u to v */
    graph[v][u] = 1; /* Mark road from village v to u (bidirectional) */
    strcpy(route[u][v], name); /* Save road name for u -> v */
    strcpy(route[v][u], name); /* Save road name for v -> u */
}

/* * Task: Deletes a connection between two villages.
 */
void deleteRoute(int u, int v) {
    graph[u][v] = 0; /* Set matrix value to 0 to show no road exists */
    graph[v][u] = 0; /* Remove connection in the opposite direction */
    route[u][v][0] = '\0'; /* Make the road name string 'empty' by starting with \0 */
    route[v][u][0] = '\0';
}

// Task: Breadth-First Search (BFS) to find the shortest path.
void bfs(int start, int end) {
    int q[N], front = 0, rear = 0; /* Initialize a Queue (FIFO) for traversal */
    int visited[N] = {0}, parent[N]; /* Track visited nodes and breadcrumb trail */
    char used[N][50]; /* Store the road name used to reach each village */

    /* Initialization task: set all parents to -1 to show they are empty */
    for (int i = 0; i < N; i++) {
        parent[i] = -1;
    }
    /* Start journey: Add the starting village to the queue and mark as visited */
    q[rear++] = start;
    visited[start] = 1;

    /* Main loop: Continue as long as there are villages left in the queue to check */
    while (front < rear) {
        int u = q[front++]; /* Take the next village from the front of the queue */

        /* Condition: If we reached the destination village, stop the search */
        if (u == end) break;

        /* Task: Check every village in the realm to see if it's a neighbor */
        for (int v = 0; v < N; v++) {
            /* Condition: A road exists AND we haven't visited this village yet */
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1; /* Mark as visited so we don't go in circles */
                parent[v] = u;  /* Record that we reached 'v' from 'u' */
                strcpy(used[v], route[u][v]); /* Save the name of the road we crossed */
                q[rear++] = v; /* Add this neighbor to the back of the queue */
            }
        }
    }

    /* Condition: If the destination was never visited, the quest failed */
    if (!visited[end]) {
        printf("\n😱 Path from %s to %s is blocked by darkness.\n", village[start], village[end]);
        return;
    }

    /* Path Reconstruction Task: Trace parents backward from 'end' to 'start' */
    int path[N], count = 0;
    int cur = end;
    while (cur != -1) {
        path[count++] = cur;
        cur = parent[cur]; /* Move to the predecessor */
    }

    /* Output Task: Print the journey in forward order */
    printf("\n🗡️ Journey from %s:\n", village[start]);
    for (int i = count - 1; i > 0; i--) {
        int to = path[i - 1];
        printf("⚔️ Cross '%s' to reach %s.\n", used[to], village[to]);
    }
}

int main() {
    /* Step 1: Initialize the world by naming villages */
    printf("🧙‍♂️ Name the 9 mystical villages:\n");
    for (int i = 0; i < N; i++) {
        printf("Village %d: ", i + 1);
        fgets(village[i], 50, stdin);
        removeNewline(village[i]);
    }

    int choice;
    while (1) {
        /* Step 2: Display the Menu */
        printf("\n=== Quest Menu ===\n1. Add Road\n2. Remove Road\n3. Quest\n0. Exit\nChoice: ");
        
        /* Condition: Check if input is a valid number */
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input.\n");
            while (getchar() != '\n'); /* Clear the bad input from buffer */
            continue;
        }
        while (getchar() != '\n'); /* Clear newline left by scanf */

        /* Task: Handle User Choices */
        if (choice == 0) break;

        if (choice == 1) {
            char a[50], b[50], r[50];
            printf("From: "); fgets(a, 50, stdin); removeNewline(a);
            printf("To: "); fgets(b, 50, stdin); removeNewline(b);
            printf("Road: "); fgets(r, 50, stdin); removeNewline(r);

            int u = getIndex(a), v = getIndex(b);
            /* Condition: Only add if both names exist */
            if (u != -1 && v != -1) addRoute(u, v, r);
            else printf("❌ Error: Village not found.\n");
        }
        
        /* ... Choice 2 (Delete) and 3 (Quest) follow similar logic ... */
        if (choice == 3) {
            char a[50], b[50];
            printf("Start: "); fgets(a, 50, stdin); removeNewline(a);
            printf("End: "); fgets(b, 50, stdin); removeNewline(b);
            int s = getIndex(a), e = getIndex(b);
            if (s != -1 && e != -1) bfs(s, e);
        }
    }
    return 0;
}