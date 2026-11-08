#include <stdio.h> 
// Global metric counters 
long long comparisons = 0;//total element comparisons across sorting routines
long long shifts = 0; //total element shifts and data movements

// Global counter for tracking partition step numbers in ascending sort
int partitionStepAsc = 1;

// Global counter for tracking partition step numbers in descending sort
int partitionStepDesc = 1;

// Global variable to choose pivot position: value will be assigned via user input in main()
int pivotChoice;

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
            // brackets indicate these elements are not part of the current partitioning step
        }
        // Check if the element matches the pivot value within the active range
        else if (arr[i] == pivot_val) {
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

// Function to partition subarray in ASCENDING order using Hoare's scheme (without while(1))
int partitionAscending(int arr[], int low, int high, int total_size) {
    // Print partition step header with step count
    printf("Partition step %d\n", partitionStepAsc++);

    // Print the current subarray and its active index bounds
    printf("Current subarray (indices %d to %d): ", low, high);
    // Display elements of the current subarray segment
    printSubarray(arr, low, high);
    // Print newline character
    printf("\n");

    // Variable to record which initial index position the pivot was selected from
    int selected_pivot_index;

    // Check if user selected last element as pivot
    if (pivotChoice == 2) {
        // Record high as the original index of the pivot
        selected_pivot_index = high;
        // Swap last element with first element so Hoare's pointers can pivot off arr[low]
        swap(arr, low, high);
    } else {
        // Record low as the original index of the pivot (First element)
        selected_pivot_index = low;
    }

    // Pick pivot value from low position
    int pivot = arr[low];
    
    // Display selected pivot and its initial index position
    printf("Selected pivot: %d, initial index: %d\n", pivot, selected_pivot_index);

    // Initialize left pointer to low
    int i = low;
    // Initialize right pointer to high
    int j = high;

    // Print partition header indicating the active range and pivot value
    printf("\n--- Partitioning Range [%d to %d] with Pivot = %d (Ascending - Hoare) ---\n", low, high, pivot);
    // Print label for initial state before scan starts
    printf("Before pass:  ");
    // Output full array state highlighting the active sub-range and pivot
    printCurrentArray(arr, total_size, low, high, pivot);

    // Run while pointers have not crossed (NO infinite loop / NO while(1))
    while (i < j) {
        // Advance left pointer while elements are smaller than or equal to pivot
        while (i <= high && arr[i] <= pivot) {
            i++;           // Move left index rightward
            comparisons++; // Count comparison against pivot
        }

        // Retreat right pointer while elements are strictly greater than pivot
        while (j >= low && arr[j] > pivot) {
            j--;           // Move right index leftward
            comparisons++; // Count comparison against pivot
        }

        // Swap out-of-order elements only if pointers have not met or crossed
        if (i < j) {
            swap(arr, i, j);
            // Print swapped element values
            printf("  Swap %d & %d:  ", arr[j], arr[i]);
            // Output intermediate array layout right after the swap
            printCurrentArray(arr, total_size, low, high, pivot);
        }
    }

    // Place pivot from low into its resting position at index j
    swap(arr, low, j);

    // Print label for array state after placing pivot
    printf("Pivot placed: ");
    // Output array showing pivot fixed in place
    printCurrentArray(arr, total_size, low, high, pivot);

    // Display the subarray state after partitioning
    printf("Subarray after partitioning: ");
    // Print elements of the partitioned subarray segment
    printSubarray(arr, low, high);
    // Print newline character
    printf("\n");

    // Check if left partition subarray has elements
    if (j - 1 >= low) {
        // Print left subarray header with valid index bounds
        printf("Left subarray (indices %d to %d): ", low, j - 1);
        // Print elements of left subarray
        printSubarray(arr, low, j - 1);
        // Print newline character
        printf("\n");
    } else {
        // Print empty label if no elements exist on left
        printf("Left subarray: [empty]\n");
    }

    // Display pivot value and its final index
    printf("Pivot: %d, final index: %d\n", pivot, j);

    // Check if right partition subarray has elements
    if (j + 1 <= high) {
        // Print right subarray header with valid index bounds
        printf("Right subarray (indices %d to %d): ", j + 1, high);
        // Print elements of right subarray
        printSubarray(arr, j + 1, high);
        // Print newline character
        printf("\n\n");
    } else {
        // Print empty label if no elements exist on right
        printf("Right subarray: [empty]\n\n");
    }

    // Return final resting index of the pivot
    return j;
}

// Recursive function to execute Quick Sort in ASCENDING order using Hoare's scheme
void quickSortAscending(int arr[], int low, int high, int total_size) {
    // Ensure the subarray segment has at least two elements
    if (low < high) {
        // Partition array and retrieve fixed pivot index j
        int pi = partitionAscending(arr, low, high, total_size);

        // Recursively sort left subarray from low to pi - 1
        quickSortAscending(arr, low, pi - 1, total_size);

        // Recursively sort right subarray from pi + 1 to high
        quickSortAscending(arr, pi + 1, high, total_size);
    }
}

// Function to partition subarray in DESCENDING order using Hoare's scheme (without while(1))
int partitionDescending(int arr[], int low, int high, int total_size) {
    // Print partition step header with step count
    printf("Partition step %d\n", partitionStepDesc++);

    // Print the current subarray and its active index bounds
    printf("Current subarray (indices %d to %d): ", low, high);
    // Display elements of the current subarray segment
    printSubarray(arr, low, high);
    // Print newline character
    printf("\n");

    // Variable to record which initial index position the pivot was selected from
    int selected_pivot_index;

    // Check if user selected last element as pivot
    if (pivotChoice == 2) {
        // Record high as the original index of the pivot
        selected_pivot_index = high;
        // Swap last element with first element so Hoare's pointers can pivot off arr[low]
        swap(arr, low, high);
    } else {
        // Record low as the original index of the pivot (First element)
        selected_pivot_index = low;
    }

    // Pick pivot value from low position
    int pivot = arr[low];
    
    // Display selected pivot and its initial index position
    printf("Selected pivot: %d, initial index: %d\n", pivot, selected_pivot_index);

    // Initialize left pointer to low
    int i = low;
    // Initialize right pointer to high
    int j = high;

    // Print partition header indicating the active range and pivot value
    printf("\n--- Partitioning Range [%d to %d] with Pivot = %d (Descending - Hoare) ---\n", low, high, pivot);
    // Print label for initial state before scan starts
    printf("Before pass:  ");
    // Output full array state highlighting the active sub-range and pivot
    printCurrentArray(arr, total_size, low, high, pivot);

    // Run while pointers have not crossed (NO infinite loop / NO while(1))
    while (i < j) {
        // Advance left pointer while elements are greater than or equal to pivot (descending)
        while (i <= high && arr[i] >= pivot) {
            i++;           // Move left index rightward
            comparisons++; // Count comparison against pivot
        }

        // Retreat right pointer while elements are strictly smaller than pivot (descending)
        while (j >= low && arr[j] < pivot) {
            j--;           // Move right index leftward
            comparisons++; // Count comparison against pivot
        }

        // Swap out-of-order elements only if pointers have not met or crossed
        if (i < j) {
            swap(arr, i, j);
            // Print swapped element values
            printf("  Swap %d & %d:  ", arr[j], arr[i]);
            // Output intermediate array layout right after the swap
            printCurrentArray(arr, total_size, low, high, pivot);
        }
    }

    // Place pivot from low into its resting position at index j
    swap(arr, low, j);

    // Print label for array state after placing pivot
    printf("Pivot placed: ");
    // Output array showing pivot fixed in place
    printCurrentArray(arr, total_size, low, high, pivot);

    // Display the subarray state after partitioning
    printf("Subarray after partitioning: ");
    // Print elements of the partitioned subarray segment
    printSubarray(arr, low, high);
    // Print newline character
    printf("\n");

    // Check if left partition subarray has elements
    if (j - 1 >= low) {
        // Print left subarray header with valid index bounds
        printf("Left subarray (indices %d to %d): ", low, j - 1);
        // Print elements of left subarray
        printSubarray(arr, low, j - 1);
        // Print newline character
        printf("\n");
    } else {
        // Print empty label if no elements exist on left
        printf("Left subarray: [empty]\n");
    }

    // Display pivot value and its final index
    printf("Pivot: %d, final index: %d\n", pivot, j);

    // Check if right partition subarray has elements
    if (j + 1 <= high) {
        // Print right subarray header with valid index bounds
        printf("Right subarray (indices %d to %d): ", j + 1, high);
        // Print elements of right subarray
        printSubarray(arr, j + 1, high);
        // Print newline character
        printf("\n\n");
    } else {
        // Print empty label if no elements exist on right
        printf("Right subarray: [empty]\n\n");
    }

    // Return final resting index of the pivot
    return j;
}

// Recursive function to execute Quick Sort in DESCENDING order using Hoare's scheme
void quickSortDescending(int arr[], int low, int high, int total_size) {
    // Ensure the subarray segment has at least two elements
    if (low < high) {
        // Partition array and retrieve fixed pivot index j
        int pi = partitionDescending(arr, low, high, total_size);

        // Recursively sort left subarray from low to pi - 1
        quickSortDescending(arr, low, pi - 1, total_size);

        // Recursively sort right subarray from pi + 1 to high
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

    // Prompt user to select which pivot position rule to run
    printf("Choose Pivot Position:\n");
    printf("1. First Element as Pivot\n");
    printf("2. Last Element as Pivot\n");
    printf("Enter choice (1 or 2): ");
    // Take user input directly inside main to initialize pivotChoice
    scanf("%d", &pivotChoice);
    printf("\n");

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