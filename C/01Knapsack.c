#include <stdio.h>

// Global comparison counter to track total checks made in the DP table
long long comparisons = 0;

int max(int a, int b) {
    comparisons++; // Count the comparison between taking vs excluding the item
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Function to solve 0/1 Knapsack using Dynamic Programming Tabulation
int knapsack01(int W, int Weight[], int Value[], int n) {
    // Declare DP table V of size (n + 1) rows and (W + 1) columns
    int V[50][100];

    // Base case: 0 items available yields 0 value for all capacities
    for (int c = 0; c <= W; c++) {
        V[0][c] = 0;
    }

    // Base case: 0 capacity yields 0 value for all item counts
    for (int i = 1; i <= n; i++) {
        V[i][0] = 0;
    }

    // Main nested loops: fill table row by row and column by column
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= W; c++) {
            // Count the weight capacity check
            comparisons++;

            // If item fits in the current capacity c
            if (Weight[i - 1] <= c) {
                // Apply max() to choose between taking item i vs excluding item i
                V[i][c] = max(Value[i - 1] + V[i - 1][c - Weight[i - 1]], V[i - 1][c]);
            } 
            // If item is too heavy, carry down the previous row's value
            else {
                V[i][c] = V[i - 1][c];
            }
        }
    }

    // Print the constructed DP table V
    printf("\nConstructed DP Table V (Rows: Items 0 to %d, Columns: Capacity 0 to %d):\n", n, W);
    for (int i = 0; i <= n; i++) {
        printf("Item %d | ", i);
        for (int c = 0; c <= W; c++) {
            printf("%3d ", V[i][c]);
        }
        printf("\n");
    }

    // Backtracking to find and display selected items
    printf("\nSelected items for maximum profit:\n");
    int res = V[n][W];
    //n is the number of items, W is the capacity of the knapsack
    int remaining_capacity = W;
    for (int i = n; i > 0 && res > 0; i--) {
        comparisons++; // Count check comparing res against V[i - 1][remaining_capacity]
        if (res != V[i - 1][remaining_capacity]) {
            printf("- Item %d (Weight: %d, Value: %d)\n", i, Weight[i - 1], Value[i - 1]);
            res -= Value[i - 1];                  // Deduct value of chosen item
            remaining_capacity -= Weight[i - 1];   // Deduct weight of chosen item
        }
    }

    // Maximum value sits at bottom-right cell V[n][W]
    return V[n][W];
}

int main() {
    int n;
    int W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int Weight[50];
    int Value[50];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i);
        scanf("%d %d", &Weight[i], &Value[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    comparisons = 0;

    int maxValue = knapsack01(W, Weight, Value, n);

    printf("\nMaximum Value: %d\n", maxValue);
    printf("Total Comparisons Made: %lld\n", comparisons);

    return 0;
}