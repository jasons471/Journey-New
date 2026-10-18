#include <stdio.h>

// Global variable to track total shifts across deletion operations
int total_shifts = 0;
// Global variable to track total boundary checks and comparisons
int total_comparisons = 0;

// Function to print current active array elements on a single line
void Print_Current_Array(int arr[], int n) {
    // Print opening bracket for array display
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    // Print closing bracket and end line
    printf("]\n");
}

void Input_Array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// Function to delete the first element (index 0) with shift tracking and intermediate views
int Delete_From_Start(int arr[], int n) {
    // Check if the array is already empty
    total_comparisons++;
    if (n <= 0) {
        // Display underflow warning
        printf("Error: Array is already empty.\n");
        // Return unchanged size
        return n;
    }

    // Display notice of operation
    printf("Deleting element %d from index 0...\n", arr[0]);

    // Shift every subsequent element to the left starting from index 0
    for (int i = 0; i < n - 1; i++) {
        // Count loop condition comparison
        total_comparisons++;
        // Overwrite element at index i with element at index i + 1
        arr[i] = arr[i + 1];
        // Increment global shifts counter
        total_shifts++;
        // Print intermediate array state showing this specific shift
        printf("  Shift %d (moved arr[%d] to arr[%d]): ", total_shifts, i + 1, i);
        // Print array using current active length n
        Print_Current_Array(arr, n);
    }
    // Count final loop exit comparison
    total_comparisons++;

    // Decrease the logical size of the array by 1
    n = n - 1;
    // Return the updated array size
    return n;
}

// Function to delete the last element (index n - 1)
int Delete_From_End(int arr[], int n) {
    // Check if the array is empty
    total_comparisons++;
    if (n <= 0) {
        // Display underflow warning
        printf("Error: Array is already empty.\n");
        // Return unchanged size
        return n;
    }

    // Display element being removed from the end
    printf("Deleting last element %d from index %d...\n", arr[n - 1], n - 1);
    // Deleting from end requires 0 shifts because decrementing size removes it directly
    printf("  No elements need to shift for end deletion.\n");

    // Decrease the active array size by 1
    n = n - 1;
    // Return updated array size
    return n;
}

// Function to delete an element from any valid index position
int Delete_From_Position(int arr[], int n, int pos) {
    // Check if array has elements to delete
    total_comparisons++;
    if (n <= 0) {
        // Display underflow warning
        printf("Error: Array is empty.\n");
        // Return unchanged size
        return n;
    }

    // Validate that pos is within valid bounds [0 to n - 1]
    total_comparisons += 2;
    if (pos < 0 || pos >= n) {
        // Display out-of-bounds error
        printf("Error: Invalid position %d. Must be between 0 and %d.\n", pos, n - 1);
        // Return unchanged size
        return n;
    }

    // Display element being deleted
    printf("Deleting element %d at index %d...\n", arr[pos], pos);

    // Shift elements leftward starting from pos up to n - 2
    for (int i = pos; i < n - 1; i++) {
        // Count loop condition comparison
        total_comparisons++;
        // Overwrite element at index i with value from i + 1
        arr[i] = arr[i + 1];
        // Increment global shifts counter
        total_shifts++;
        // Print intermediate array state right after this shift occurs
        printf("  Shift %d (moved arr[%d] to arr[%d]): ", total_shifts, i + 1, i);
        // Print current elements
        Print_Current_Array(arr, n);
    }
    // Count final loop exit comparison
    total_comparisons++;

    // Reduce array element count by 1
    n = n - 1;
    // Return new size
    return n;
}

// Main function
int main() {
    int arr[20];
    int n;
    int pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    Input_Array(arr, n);

    printf("\nOriginal array: ");
    Print_Current_Array(arr, n);

    // Reset metrics before starting tests
    total_shifts = 0;
    total_comparisons = 0;

    printf("\n================ 1. DELETE FROM START ================\n");
    // Call delete from start
    n = Delete_From_Start(arr, n);
    // Display resulting array with updated size
    printf("Array after start deletion: ");
    Print_Current_Array(arr, n);
    // Display counts
    printf("Total shifts so far: %d\n", total_shifts);
    printf("Total comparisons so far: %d\n", total_comparisons);

    printf("\n================= 2. DELETE FROM END =================\n");
    // Call delete from end
    n = Delete_From_End(arr, n);
    // Display resulting array with updated size
    printf("Array after end deletion: ");
    Print_Current_Array(arr, n);
    // Display counts
    printf("Total shifts so far: %d\n", total_shifts);
    printf("Total comparisons so far: %d\n", total_comparisons);

    printf("\n============= 3. DELETE FROM ANY POSITION =============\n");
    // Prompt user for custom position
    printf("Enter position to delete (0 to %d): ", n - 1);
    // Read position
    scanf("%d", &pos);
    // Call delete from custom position
    n = Delete_From_Position(arr, n, pos);
    // Display final array with updated size
    printf("Final array after position deletion: ");
    Print_Current_Array(arr, n);
    // Display grand totals
    printf("Total shifts overall: %d\n", total_shifts);
    printf("Total comparisons overall: %d\n", total_comparisons);

    return 0;
}