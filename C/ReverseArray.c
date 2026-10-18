#include <stdio.h>

// Global tracking metric to count total value swaps performed
int total_swaps = 0;
// Global tracking metric to count total data shifts and write assignments
int total_shifts = 0;
// Global tracking metric to count total loop boundary condition checks
int total_comparisons = 0;

void printCurrentArray(int arr[], int n) {
    // Print opening bracket
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    // Print closing bracket and move to the next line
    printf("]\n");
}

// Function to swap two elements by their array indices without pointer syntax
void swapByIndex(int arr[], int i, int j) {
    // Store value of the first index in a temporary variable
    int temp = arr[i];
    // Copy value from the second index to the first index
    arr[i] = arr[j];
    // Copy temporary value to the second index
    arr[j] = temp;
    // Increment global swap counter by 1
    total_swaps++;
    // Increment shifts by 3 to count all three variable assignment writes
    total_shifts += 3;
}

// Function to reverse the array in place showing intermediate steps and counts
void reverseArray(int arr[], int n) {
    // Pointer/index marking the start of the reversal boundary
    int start = 0;
    // Pointer/index marking the end of the reversal boundary
    int end = n - 1;
    // Step counter for visual display tracking
    int step = 1;

    // Reset all global tracking metrics before starting
    total_swaps = 0;
    total_shifts = 0;
    total_comparisons = 0;

    // Print starting label
    printf("Initial Array: ");
    // Display initial array state
    printCurrentArray(arr, n);
    // Print section header for reversal steps
    printf("\n--- Intermediate Reversal Steps ---\n");

    // Loop until start and end pointers meet or cross each other
    while (start < end) {
        // Count the successful loop condition check
        total_comparisons++;

        // Perform index-based swap between start and end elements
        swapByIndex(arr, start, end);

        // Display current step number and the indices that were swapped
        printf("Step %d (Swapped index %d and %d): ", step, start, end);
        // Display intermediate array state after this swap
        printCurrentArray(arr, n);

        // Increment step counter for next output
        step++;
        // Advance start index toward the center
        start++;
        // Move end index backward toward the center
        end--;
    }

    // Count the final comparison where start >= end causes loop termination
    total_comparisons++;
}

// Function to display the aggregated count metrics after completion
void displayMetrics(int n) {
    // Print divider header for metrics
    printf("\n--- Operations & Counts Summary ---\n");
    // Display total number of elements in the array
    printf("Array Size (n):                 %d\n", n);
    // Display total number of swaps executed
    printf("Total Swaps:                    %d\n", total_swaps);
    // Display total number of data movements / shifts (writes)
    printf("Total Shifts (Data Writes):     %d\n", total_shifts);
    // Display total number of condition comparisons evaluated
    printf("Total Comparisons:              %d\n", total_comparisons);
}

int main() {
    // Declare and initialize sample array
    int arr[] = {12, 24, 36, 48, 60, 72};
    // Calculate total number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call reversal function to process array in place
    reverseArray(arr, n);

    // Call display function to output all tracked operations and counts
    displayMetrics(n);

    return 0;
}