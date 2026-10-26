#include <stdio.h> 
// Global metric counters 
long long comparisons = 0;//total element comparisons across sorting routines
long long shifts = 0; //total element shifts and data movements

// Global counter for tracking partition step numbers in ascending sort
int partitionStepAsc = 1;

// Global counter for tracking partition step numbers in descending sort
int partitionStepDesc = 1;

// Helper function to print elements of a subarray enclosed in brackets [x y z]
void printSubarray(int arr[], int start, int end) {
    // Print opening bracket
    printf("[");
    // Loop through indices from start to end
    for (int i = start; i <= end; i++) {
        // Print the element value
        printf("%d", arr[i]);
        // Print space between elements if not the last element
        if (i < end) {
            printf(" ");
        }
    }
    // Print closing bracket
    printf("]");
}

// Function to display the intermediate array state with active partition and pivot highlights
void printCurrentArray(int arr[], int total_size, int low, int high, int pivot_val) {
    // Iterate across every index of the full array
    for (int i = 0; i < total_size; i++) {
        // Check if current index lies outside the active recursion subarray
        if (i < low || i > high) {
            // Print inactive elements wrapped in parentheses
            printf(" (%d)", arr[i]);
        }
        // Check if the element is the active pivot located at the high boundary
        else if (arr[i] == pivot_val && i == high) {
            // Print pivot marked with brackets and an asterisk
            printf(" [%d*]", arr[i]);
        }
        // Element is actively part of the current subarray segment
        else {
            // Print active partition elements with uniform spacing
            printf("  %d ", arr[i]);
        }
    }
    // Print newline to terminate the array state line
    printf("\n");
}

// Function to swap two elements in an array using their indices
void swap(int arr[], int i, int j) {
    // Store value at index i in a temporary variable
    int temp = arr[i];
    // Assign value from index j to index i
    arr[i] = arr[j];
    // Assign stored temporary value to index j
    arr[j] = temp;
    // Increment global shifts/data movements count by 3 for the swap assignment steps
    shifts += 3;
}

// Function to partition subarray in ASCENDING order using Lomuto scheme
int partitionAscending(int arr[], int low, int high, int total_size) {
    // Print partition step header with step count
    printf("Partition step %d\n", partitionStepAsc++);

    // Print the current subarray and its active index bounds
    printf("Current subarray (indices %d to %d): ", low, high);
    // Display elements of the current subarray segment
    printSubarray(arr, low, high);
    // Print newline character
    printf("\n");

    // Pick the element at the high boundary as the pivot
    int pivot = arr[high];
    
    // Display selected pivot and its initial index position
    printf("Selected pivot: %d, initial index: %d\n", pivot, high);

    // Initialize smaller element boundary tracker to one position before low
    int i = (low - 1);

    // Print partition header indicating the active range and pivot value
    printf("\n--- Partitioning Range [%d to %d] with Pivot = %d (Ascending) ---\n", low, high, pivot);
    // Print label for initial state before scan starts
    printf("Before pass:  ");
    // Output full array state highlighting the active sub-range and pivot
    printCurrentArray(arr, total_size, low, high, pivot);

    // Scan through all elements from low to high - 1
    for (int j = low; j < high; j++) {
        // Increment global comparisons counter for this check
        comparisons++;

        // Determine if current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            // Advance the smaller element boundary
            i++;
            // Check if boundary index and current index differ before swapping
            if (i != j) {
                // Swap elements at boundary index i and current scan index j
                swap(arr, i, j);
                // Print swapped element values
                printf("  Swap %d & %d:  ", arr[j], arr[i]);
                // Output intermediate array layout right after the swap
                printCurrentArray(arr, total_size, low, high, pivot);
            }
        }
    }

    // Place pivot at its final sorted boundary position by swapping with index i + 1
    swap(arr, i + 1, high);

    // Print label for array state after placing pivot
    printf("Pivot placed: ");
    // Output array showing pivot fixed in place
    printCurrentArray(arr, total_size, low, high, pivot);

    // Record final resting index of the pivot
    int final_pivot_index = i + 1;

    // Display the subarray state after partitioning
    printf("Subarray after partitioning: ");
    // Print elements of the partitioned subarray segment
    printSubarray(arr, low, high);
    // Print newline character
    printf("\n");

    // Check if left partition subarray has elements
    if (final_pivot_index - 1 >= low) {
        // Print left subarray header with valid index bounds
        printf("Left subarray (indices %d to %d): ", low, final_pivot_index - 1);
        // Print elements of left subarray
        printSubarray(arr, low, final_pivot_index - 1);
        // Print newline character
        printf("\n");
    } else {
        // Print empty label if no elements exist on left
        printf("Left subarray: [empty]\n");
    }

    // Display pivot value and its final index
    printf("Pivot: %d, final index: %d\n", pivot, final_pivot_index);

    // Check if right partition subarray has elements
    if (final_pivot_index + 1 <= high) {
        // Print right subarray header with valid index bounds
        printf("Right subarray (indices %d to %d): ", final_pivot_index + 1, high);
        // Print elements of right subarray
        printSubarray(arr, final_pivot_index + 1, high);
        // Print newline character
        printf("\n\n");
    } else {
        // Print empty label if no elements exist on right
        printf("Right subarray: [empty]\n\n");
    }

    // Return final resting index of the pivot
    return (i + 1);
}

// Recursive function to execute Quick Sort in ASCENDING order
void quickSortAscending(int arr[], int low, int high, int total_size) {
    // Ensure the subarray segment has at least two elements
    if (low < high) {
        // Partition array and retrieve fixed pivot index
        int pi = partitionAscending(arr, low, high, total_size);

        // Recursively sort the elements to the left of the pivot
        quickSortAscending(arr, low, pi - 1, total_size);

        // Recursively sort the elements to the right of the pivot
        quickSortAscending(arr, pi + 1, high, total_size);
    }
}
// Function to partition subarray in DESCENDING order using Lomuto scheme
int partitionDescending(int arr[], int low, int high, int total_size) {
    // Print partition step header with step count
    printf("Partition step %d\n", partitionStepDesc++);

    // Print the current subarray and its active index bounds
    printf("Current subarray (indices %d to %d): ", low, high);
    // Display elements of the current subarray segment
    printSubarray(arr, low, high);
    // Print newline character
    printf("\n");

    // Pick the element at the high boundary as the pivot
    int pivot = arr[high];
    
    // Display selected pivot and its initial index position
    printf("Selected pivot: %d, initial index: %d\n", pivot, high);

    // Initialize larger element boundary tracker to one position before low
    int i = (low - 1);

    // Print partition header indicating the active range and pivot value
    printf("\n--- Partitioning Range [%d to %d] with Pivot = %d (Descending) ---\n", low, high, pivot);
    // Print label for initial state before scan starts
    printf("Before pass:  ");
    // Output full array state highlighting the active sub-range and pivot
    printCurrentArray(arr, total_size, low, high, pivot);

    // Scan through all elements from low to high - 1
    for (int j = low; j < high; j++) {
        // Increment global comparisons counter for this check
        comparisons++;

        // Determine if current element is greater than or equal to pivot
        if (arr[j] >= pivot) {
            // Advance the larger element boundary
            i++;
            // Check if boundary index and current index differ before swapping
            if (i != j) {
                // Swap elements at boundary index i and current scan index j
                swap(arr, i, j);
                // Print swapped element values
                printf("  Swap %d & %d:  ", arr[j], arr[i]);
                // Output intermediate array layout right after the swap
                printCurrentArray(arr, total_size, low, high, pivot);
            }
        }
    }

    // Place pivot at its final sorted boundary position by swapping with index i + 1
    swap(arr, i + 1, high);

    // Print label for array state after placing pivot
    printf("Pivot placed: ");
    // Output array showing pivot fixed in place
    printCurrentArray(arr, total_size, low, high, pivot);

    // Record final resting index of the pivot
    int final_pivot_index = i + 1;

    // Display the subarray state after partitioning
    printf("Subarray after partitioning: ");
    // Print elements of the partitioned subarray segment
    printSubarray(arr, low, high);
    // Print newline character
    printf("\n");

    // Check if left partition subarray has elements
    if (final_pivot_index - 1 >= low) {
        // Print left subarray header with valid index bounds
        printf("Left subarray (indices %d to %d): ", low, final_pivot_index - 1);
        // Print elements of left subarray
        printSubarray(arr, low, final_pivot_index - 1);
        // Print newline character
        printf("\n");
    } else {
        // Print empty label if no elements exist on left
        printf("Left subarray: [empty]\n");
    }

    // Display pivot value and its final index
    printf("Pivot: %d, final index: %d\n", pivot, final_pivot_index);

    // Check if right partition subarray has elements
    if (final_pivot_index + 1 <= high) {
        // Print right subarray header with valid index bounds
        printf("Right subarray (indices %d to %d): ", final_pivot_index + 1, high);
        // Print elements of right subarray
        printSubarray(arr, final_pivot_index + 1, high);
        // Print newline character
        printf("\n\n");
    } else {
        // Print empty label if no elements exist on right
        printf("Right subarray: [empty]\n\n");
    }

    // Return final resting index of the pivot
    return (i + 1);
}

// Recursive function to execute Quick Sort in DESCENDING order
void quickSortDescending(int arr[], int low, int high, int total_size) {
    // Ensure the subarray segment has at least two elements
    if (low < high) {
        // Partition array and retrieve fixed pivot index
        int pi = partitionDescending(arr, low, high, total_size);

        // Recursively sort the elements to the left of the pivot
        quickSortDescending(arr, low, pi - 1, total_size);

        // Recursively sort the elements to the right of the pivot
        quickSortDescending(arr, pi + 1, high, total_size);
    }
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arrAsc[] = {24, 9, 29, 14, 19, 27};
    int arrDesc[] = {24, 9, 29, 14, 19, 27};
    int n = sizeof(arrAsc) / sizeof(arrAsc[0]);

   printf("Original array (Ascending run):\n");
    printArray(arrAsc, n);

    // Reset comparisons count before running ascending sort
    comparisons = 0;
    // Reset shifts count before running ascending sort
    shifts = 0;

    // Reset partition step counter before starting
    partitionStepAsc = 1;

    // Execute ascending quicksort on the entire array
    quickSortAscending(arrAsc, 0, n - 1, n);
    printf("\nFinal Sorted array (Ascending): ");
    
    // Display sorted ascending elements
    printArray(arrAsc, n);
    
    // Display total comparisons performed during ascending sort
    printf("Number of comparisons: %lld\n", comparisons);
    // Display total shifts/data assignments performed during ascending sort
    printf("Number of shifts: %lld\n", shifts);

    // Print divider line between ascending and descending test runs
    printf("\n========================================================\n\n");


    printf("Original array (Descending run):\n");
    printArray(arrDesc, n);

    // Reset comparisons count before running descending sort
    comparisons = 0;
    // Reset shifts count before running descending sort
    shifts = 0;

    // Reset partition step counter before starting
    partitionStepDesc = 1;

    // Execute descending quicksort on the entire array
    quickSortDescending(arrDesc, 0, n - 1, n);

    printf("\nFinal Sorted array (Descending): ");
    // Display sorted descending elements
    printArray(arrDesc, n);
    // Display total comparisons performed during descending sort
    printf("Number of comparisons: %lld\n", comparisons);
    // Display total shifts/data assignments performed during descending sort
    printf("Number of shifts: %lld\n", shifts);
return 0;

}