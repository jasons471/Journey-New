#include <stdio.h>  

// Declare global counter for total comparisons performed in search operations
long long comparisons = 0;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform linear search on an unsorted array
int linearSearch(int arr[], int n, int x) {
    // Reset comparison counter before starting the search
    comparisons = 0;

    // Scan sequentially through each index of the array from 0 to n - 1
    for (int i = 0; i < n; i++) {
        // Increment comparison counter for the current element check
        comparisons++;

        // Display current element being inspected during the scan
        printf("  Iteration %d: Checking arr[%d] = %d against target %d\n", i + 1, i, arr[i], x);

        // Check if current array element matches the search target
        if (arr[i] == x) {
            // Return index where target element was found
            return i;
        }
    }

    // Return -1 if target is not present in the array
    return -1;
}

// Binary Search for ASCENDING sorted arrays (smaller elements at left, larger at right)
int binarySearchAscending(int arr[], int n, int x) {
    // Reset comparison counter before starting the search
    comparisons = 0;

    // Set lower search boundary to the first index
    int low = 0;
    // Set upper search boundary to the last index
    int high = n - 1;
    // Step tracker for visual trace
    int step = 1;

    // Continue loop as long as the search window is valid
    while (low <= high) {
        // Compute middle index without integer overflow
        int mid = low + (high - low) / 2;

        // Print active search boundaries and middle element for this step
        printf("  Step %d: Range [%d to %d], Mid index = %d, Mid value = %d\n", step++, low, high, mid, arr[mid]);

        // Increment comparison counter for checking equality
        comparisons++;

        // Check if the middle element is equal to the target
        if (arr[mid] == x) {
            // Return index of found element
            return mid;
        }

        // Increment comparison counter for determining search direction
        comparisons++;

        // In ascending order, if middle element is less than target, target lies in right half
        if (arr[mid] < x) {
            // Shift lower boundary to eliminate left half and mid
            low = mid + 1;
        } else {
            // Shift upper boundary to eliminate right half and mid
            high = mid - 1;
        }
    }

    // Return -1 if element was not found in the array
    return -1;
}

// Binary Search for DESCENDING sorted arrays (larger elements at left, smaller at right)
int binarySearchDescending(int arr[], int n, int x) {
    // Reset comparison counter before starting the search
    comparisons = 0;

    // Set lower search boundary to the first index
    int low = 0;
    // Set upper search boundary to the last index
    int high = n - 1;
    // Step tracker for visual trace
    int step = 1;

    // Continue loop as long as the search window is valid
    while (low <= high) {
        // Compute middle index without integer overflow
        int mid = low + (high - low) / 2;

        // Print active search boundaries and middle element for this step
        printf("  Step %d: Range [%d to %d], Mid index = %d, Mid value = %d\n", step++, low, high, mid, arr[mid]);

        // Increment comparison counter for checking equality
        comparisons++;

        // Check if the middle element matches target
        if (arr[mid] == x) {
            // Return index of found element
            return mid;
        }

        // Increment comparison counter for determining search direction
        comparisons++;

        // In descending order, if middle element is less than target, target lies in left half
        if (arr[mid] < x) {
            // Shift upper boundary to eliminate right half and mid
            high = mid - 1;
        } else {
            // Shift lower boundary to eliminate left half and mid
            low = mid + 1;
        }
    }

    // Return -1 if element was not found in the array
    return -1;
}

int main() {
    int arrUnsorted[] = {45, 12, 89, 34, 7, 23};
    // Compute total number of elements in unsorted array
    int nUnsorted = sizeof(arrUnsorted) / sizeof(arrUnsorted[0]);

    // Declare and initialize an ascending sorted array for Ascending Binary Search
    int arrAsc[] = {7, 12, 23, 34, 45, 89};
    // Compute total number of elements in ascending array
    int nAsc = sizeof(arrAsc) / sizeof(arrAsc[0]);

    // Declare and initialize a descending sorted array for Descending Binary Search
    int arrDesc[] = {89, 45, 34, 23, 12, 7};
    // Compute total number of elements in descending array
    int nDesc = sizeof(arrDesc) / sizeof(arrDesc[0]);

    // Target value to search for
    int target = 34;
    // Variable to hold the resulting index
    int index;

    // ==================== 1. LINEAR SEARCH DEMO ====================

    printf("==================== 1. LINEAR SEARCH ====================\n");
    // Display array being searched
    printf("Array: ");
    printArray(arrUnsorted, nUnsorted);
    // Print target item
    printf("Target item: %d\n", target);
    printf("Search trace:\n");

    index = linearSearch(arrUnsorted, nUnsorted, target);

    // Check if target was found
    if (index != -1) {
        // Display location of element
        printf("Result: Target %d found at index %d\n", target, index);
    } else {
        // Display not found message
        printf("Result: Target %d not found\n", target);
    }
    // Display total comparisons performed
    printf("Total comparisons: %lld\n", comparisons);
    

    // ==================== 2. ASCENDING BINARY SEARCH DEMO ====================

    printf("================ 2. BINARY SEARCH (ASCENDING) ================\n");
    printf("Array: ");
    printArray(arrAsc, nAsc);
    // Print target item
    printf("Target item: %d\n", target);
    printf("Search trace:\n");

    // Execute ascending binary search
    index = binarySearchAscending(arrAsc, nAsc, target);

    // Check if target was found
    if (index != -1) {
        // Display location of element
        printf("Result: Target %d found at index %d\n", target, index);
    } else {
        // Display not found message
        printf("Result: Target %d not found\n", target);
    }
    // Display total comparisons performed
    printf("Total comparisons: %lld\n", comparisons);
    // Note shift count
    printf("Total shifts: 0 (Searching does not move or shift array elements)\n\n");

    // ==================== 3. DESCENDING BINARY SEARCH DEMO ====================
    
    printf("================ 3. BINARY SEARCH (DESCENDING) ================\n");
    // Display sorted array being searched
    printf("Array: ");
    printArray(arrDesc, nDesc);
    // Print target item
    printf("Target item: %d\n", target);
    printf("Search trace:\n");

    // Execute descending binary search
    index = binarySearchDescending(arrDesc, nDesc, target);

    // Check if target was found
    if (index != -1) {
        // Display location of element
        printf("Result: Target %d found at index %d\n", target, index);
    } else {
        // Display not found message
        printf("Result: Target %d not found\n", target);
    }
    // Display total comparisons performed
    printf("Total comparisons: %lld\n", comparisons);
    // Note shift count
    printf("Total shifts: 0 (Searching does not move or shift array elements)\n");

    
    return 0;
}