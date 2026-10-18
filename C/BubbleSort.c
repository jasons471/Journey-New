#include <stdio.h>

// Global variable to track the total number of comparisons between adjacent elements
long long comparisons = 0;
// Global variable to track the total number of data shifts/writes across all swaps
long long shifts = 0;

// Helper function to print the current state of an array wrapped in brackets
void printCurrentArray(int arr[], int size) {
    // Print opening bracket
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    // Print closing bracket and advance to the next line
    printf("]\n");
}

// Function to swap two elements using their array indices directly
void swapByIndex(int arr[], int i, int j) {
    // Store value at index i in a temporary variable
    int temp = arr[i];
    // Copy value from index j into index i
    arr[i] = arr[j];
    // Copy temporary value into index j
    arr[j] = temp;
    // Increment shifts by 3 to count the three assignment operations in a swap
    shifts += 3;
}

// Function to perform Bubble Sort in ASCENDING order showing intermediate passes
void bubbleSortAscending(int arr[], int n) {
    // Flag to detect if any swap happened during an inner pass
    int swapped;

    // Loop through the array for up to (n - 1) passes
    for (int i = 0; i < n - 1; i++) {
        // Reset swap flag to 0 at the start of each pass
        swapped = 0;

        // Print header for the current pass
        printf("Pass %d:\n", i + 1);

        // Compare adjacent elements up to (n - i - 1) as the last i items are in place
        for (int j = 0; j < n - i - 1; j++) {
            // Increment comparison counter for adjacent comparison
            comparisons++;

            // For ascending order, check if the left element is greater than the right
            if (arr[j] > arr[j + 1]) {
                // Swap the two out-of-order adjacent elements
                swapByIndex(arr, j, j + 1);
                // Mark that a swap occurred in this pass
                swapped = 1;
                // Display the intermediate array right after this swap
                printf("  Swap arr[%d]=%d & arr[%d]=%d: ", j, arr[j + 1], j + 1, arr[j]);
                printCurrentArray(arr, n);
            }
        }

        // If no swaps occurred, the array is already completely sorted
        if (swapped == 0) {
            // Print early termination note
            printf("  No swaps in Pass %d. Array is early-sorted!\n", i + 1);
            // Break out of the outer loop
            break;
        }

        // Display array state at the completion of this pass
        printf("End of Pass %d State: ", i + 1);
        printCurrentArray(arr, n);
    }
}

// Function to perform Bubble Sort in DESCENDING order showing intermediate passes
void bubbleSortDescending(int arr[], int n) {
    // Flag to detect if any swap happened during an inner pass
    int swapped;

    // Loop through the array for up to (n - 1) passes
    for (int i = 0; i < n - 1; i++) {
        // Reset swap flag to 0 at the start of each pass
        swapped = 0;

        // Print header for the current pass
        printf("Pass %d:\n", i + 1);

        // Compare adjacent elements up to (n - i - 1)
        for (int j = 0; j < n - i - 1; j++) {
            // Increment comparison counter for adjacent comparison
            comparisons++;

            // For descending order, check if the left element is smaller than the right
            if (arr[j] < arr[j + 1]) {
                // Swap the two out-of-order adjacent elements
                swapByIndex(arr, j, j + 1);
                // Mark that a swap occurred in this pass
                swapped = 1;
                // Display the intermediate array right after this swap
                printf("  Swap arr[%d]=%d & arr[%d]=%d: ", j, arr[j + 1], j + 1, arr[j]);
                printCurrentArray(arr, n);
            }
        }

        // If no swaps occurred, the array is already completely sorted
        if (swapped == 0) {
            // Print early termination note
            printf("  No swaps in Pass %d. Array is early-sorted!\n", i + 1);
            // Break out of the outer loop
            break;
        }

        // Display array state at the completion of this pass
        printf("End of Pass %d State: ", i + 1);
        printCurrentArray(arr, n);
    }
}

// Main execution entry point
int main() {
    // Initialize sample array for ascending test run
    int arrAsc[] = {64, 34, 25, 12, 22, 11, 90};
    // Initialize identical sample array for descending test run
    int arrDesc[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate total number of elements in the array
    int n = sizeof(arrAsc) / sizeof(arrAsc[0]);

    printf("==================== BUBBLE SORT (ASCENDING) ====================\n");
    // Display original array before sorting
    printf("Original array: ");
    printCurrentArray(arrAsc, n);
    printf("\n");

    // Reset metric counters before ascending run
    comparisons = 0;
    shifts = 0;

    // Execute ascending bubble sort
    bubbleSortAscending(arrAsc, n);

    // Display final ascending sorted array
    printf("\nFinal Sorted Array (Ascending): ");
    printCurrentArray(arrAsc, n);
    // Display total comparisons performed during ascending sort
    printf("Total comparisons: %lld\n", comparisons);
    // Display total data shifts/writes performed during ascending sort
    printf("Total shifts (data writes): %lld\n", shifts);

    // Print divider between runs
    printf("\n=================================================================\n\n");

    printf("==================== BUBBLE SORT (DESCENDING) ===================\n");
    // Display original array before sorting
    printf("Original array: ");
    printCurrentArray(arrDesc, n);
    printf("\n");

    // Reset metric counters before descending run
    comparisons = 0;
    shifts = 0;

    // Execute descending bubble sort
    bubbleSortDescending(arrDesc, n);

    // Display final descending sorted array
    printf("\nFinal Sorted Array (Descending): ");
    printCurrentArray(arrDesc, n);
    // Display total comparisons performed during descending sort
    printf("Total comparisons: %lld\n", comparisons);
    // Display total data shifts/writes performed during descending sort
    printf("Total shifts (data writes): %lld\n", shifts);

    return 0;
}