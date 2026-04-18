#include <stdio.h>
#include <string.h>

#define N 9 // Number of villages in the mystical realm

// These arrays store the state of the mystical realm (the graph)
char village[N][50];      // Stores the names of the 9 villages
int graph[N][N];         // A grid showing if a road exists (1) or not (0) between villages
char route[N][N][50];    // Stores the name of the road between two villages

// Removes the extra "enter" character that fgets adds to the end of a name
void removeNewline(char str[]) {
    size_t len = strlen(str); // Get the length of the string
    if (len > 0 && str[len - 1] == '\n'){ // Check if the last character is a newline
        str[len - 1] = '\0';   // This replaces '\n' with '\0'
    }
}

// Looks up a village name and returns its index number (0-8)
int getIndex(char name[]) {
    for (int i = 0; i < N; i++)
        if (strcmp(village[i], name) == 0)
            return i;
    return -1; // Returns -1 if the village name isn't found
}

// Creates a two-way road between two villages and names the challenge
/**
 * addRoute: Adds a road between two villages.
 * u: The index number of the starting village (0-8)
 * v: The index number of the destination village (0-8)
 * name: The name of the road connecting the two villages
 */
void addRoute(int u, int v, char name[]) {
    graph[u][v] = 1; // Create the road from u to v
    graph[v][u] = 1; // Create the road from v to u
    strcpy(route[u][v], name); // Store the road name
    strcpy(route[v][u], name); // Store the road name
}

// Breaks the connection between two villages
void deleteRoute(int u, int v) {
    graph[u][v] = 0; // Remove the road from u to v
    graph[v][u] = 0; // Remove the road from v to u
    route[u][v][0] = '\0'; // Clear the road name
    route[v][u][0] = '\0'; // Clear the road name
}

// Depth-First Search (DFS) algorithm to find a path from start to end
void dfs(int start, int end) {
    int stack[N], top = -1;      // Stack to keep track of where to go next
    int visited[N] = {0};        // Tracks which villages we have already seen
    int parent[N];               // Remembers where we came from to rebuild the path later
    char used[N][50];            // Remembers which road name we used to reach a village

    // Set up initial values for the search
    for (int i = 0; i < N; i++) { // Initialize all villages
        parent[i] = -1; // No parent yet
        used[i][0] = '\0'; // No road used yet
    }

    // Start the journey at the beginning village
    stack[++top] = start; // 1. Put the starting village index into the stack. 
    // This is like putting the first location on a "To-Visit" list
    visited[start] = 1; // 2. Mark this village as 'visited' (set to 1).
    // This prevents the explorer from walking in circles and returning to the start.
    parent[start] = -1; // 3. Set the 'parent' of the start to -1.
    // Since this is the beginning, there is no "previous" village. 
    // -1 acts as a stop-sign when we trace the path back later.

    // Keep searching while there are still paths to explore in the stack
    while (top >= 0) {
        int u = stack[top--]; // Pick the most recent village added (last-in, first-out)

        if (u == end){
           break; // If we reached the destination, stop searching 
        }

        // Check all possible neighbors of the current village
        
        for (int v = 0; v < N; v++) {
            // If a road exists and we haven't visited that village yet
            if (graph[u][v] && !visited[v]) { // Condition 1: graph[u][v] checks if a road actually exists in the map.
            // Condition 2: !visited[v] checks if we have NOT been to village 'v' yet.
                visited[v] = 1; // Mark this village as visited to avoid cycles
                parent[v] = u; // Remember we came to 'v' from 'u'
                strcpy(used[v], route[u][v]); // Store the road name used to reach 'v'
                stack[++top] = v; // Push the neighbor onto the stack to dive deeper
            }
        }
    }

    // If the destination village was never reached
    if (!visited[end]) { // If we never marked the end village as visited
        printf("\n😱 You searched every path from %s to %s, but darkness blocks your way.\n", village[start], village[end]);
        // No path was found
        printf("💀 Quest Failed! Your hero returns home to prepare for another adventure.\n\n");
        return;
    }

    // Rebuild the path by tracing parents backwards from the end to the start
    int path[N], count = 0; // Array to store the path and a counter
    int cur = end; // Start from the destination village
    while (cur != -1) { // Trace back until we reach the start (parent of start is -1)
        path[count++] = cur; // Store the current village in the path
        cur = parent[cur]; // Move to the parent village
    }

    // Print the adventure story from start to finish
    printf("\n🗡️  Brave adventurer, your journey begins at %s! 🏰\n", village[start]);
    for (int i = count - 1; i > 0; i--) { // Print the path in reverse order
        int to = path[i - 1];
        printf("⚔️  You fight your way through '%s' and reach %s.\n", used[to], village[to]);
    }
    printf("🏆 Triumph! You have conquered the challenges and arrived at %s! Quest Complete! 🌟\n\n", village[end]);
}

int main() {
    printf("🧙‍♂️ Welcome, adventurer! Name the 9 mystical villages in your realm:\n");
    for (int i = 0; i < N; i++) {// Input village names
        printf("Village %d: ", i + 1);
        fgets(village[i], 50, stdin);
        removeNewline(village[i]);
    }

    int choice;
    while (1) {// Main menu loop
        printf("\n=== Quest Navigator Menu ===\n");
        printf("1. Add Road\n2. Remove Road\n3. Embark on a Quest (Find Path)\n0. Exit\nYour choice: ");
        
        // Handle non-number inputs to prevent infinite loops
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input. Try again.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n'); // Clear the buffer

        if (choice == 0) { // Exit the program
            printf("\n🛡️  Your journey ends here. Rest well, adventurer!\n");
            break;
        }

        // Logic for adding a road
        if (choice == 1) { // Add a road
            char a[50], b[50], r[50];
            printf("From (Village): "); fgets(a, 50, stdin); removeNewline(a); 
            // Input starting village
            printf("To (Village): "); fgets(b, 50, stdin); removeNewline(b);
            // Input destination village
            printf("Road name (challenge): "); fgets(r, 50, stdin); removeNewline(r);
            // Input road name

            int u = getIndex(a); // Get index of starting village
            int v = getIndex(b); // Get index of destination village
            if (u == -1 || v == -1) { // Check if villages exist
                printf("❌ One or both villages not found.\n");
            } else {
                addRoute(u, v, r);
                printf("✅ Road '%s' connecting %s and %s has been forged!\n", r, village[u], village[v]);
                // Confirmation message
            }
        }

        // Logic for removing a road
        if (choice == 2) { // Remove a road
            char a[50], b[50]; // Input villages
            printf("From (Village): "); fgets(a, 50, stdin); removeNewline(a); 
            // Input starting village
            printf("To (Village): "); fgets(b, 50, stdin); removeNewline(b);
            // Input destination village

            int u = getIndex(a);
            // Get index of starting village
            int v = getIndex(b);
            // Get index of destination village
            if (u == -1 || v == -1) {
                printf("❌ One or both villages not found.\n");
            } else {
                deleteRoute(u, v);
                printf("🧨 Road between %s and %s has collapsed!\n", village[u], village[v]);
            }
        }

        // Logic for starting the pathfinding quest
        if (choice == 3) { // Find path
            char a[50], b[50]; 
            printf("Start your quest at: "); fgets(a, 50, stdin); removeNewline(a);
            printf("Destination village: "); fgets(b, 50, stdin); removeNewline(b);

            int s = getIndex(a);
            // Get index of starting village
            int e = getIndex(b);
            // Get index of destination village
            if (s == -1 || e == -1) {
                printf("❌ One or both villages not found.\n");
            } else {
                dfs(s, e);
                // Start the quest (pathfinding)
            }
        }
    }
    return 0;
}