#include <stdio.h> 

// Global metric counters to track shifts and comparisons during sorting
long long comparisons = 0; 
long long shifts = 0;      


void swap(int arr[], int i, int j) {
    int temp = arr[i]; 
    arr[i] = arr[j];   
    arr[j] = temp;     
    shifts += 3;       
}

// Helper function to copy original array elements to a working array
void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) { 
        dest[i] = src[i];            // Copy element from source to destination
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) { 
        printf("%d ", arr[i]);       
    }
    printf("\n");                    
}

// Function to perform Selection Sort in ASCENDING order
void selectionSortAscending(int arr[], int n) {
    // Loop through the entire array up to the second-to-last element
    for (int i = 0; i < n - 1; i++) {
        // Assume the current position 'i' holds the minimum element
        int min_idx = i;

        // Loop through the unsorted part to find the true minimum element
        for (int j = i + 1; j < n; j++) {
            comparisons++; // Increment comparison counter for each check

            // Check if current element is smaller than our recorded minimum
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index of the new minimum element
            }
        }

        // Swap if the minimum element found is not already in the correct position
        if (min_idx != i) {
            swap(arr, i, min_idx); // Swap elements using the separate swap function
        }

        // Print intermediate array state after placing the i-th smallest element
        printf("After pass %d: ", i + 1);
        printArray(arr, n);
    }
}

// Function to perform Selection Sort in DESCENDING order
void selectionSortDescending(int arr[], int n) {
    // Loop through the entire array up to the second-to-last element
    for (int i = 0; i < n - 1; i++) {
        // Assume the current position 'i' holds the maximum element
        int max_idx = i;

        // Loop through the unsorted part to find the true maximum element
        for (int j = i + 1; j < n; j++) {
            comparisons++; // Increment comparison counter for each check

            // Check if current element is greater than our recorded maximum (descending check)
            if (arr[j] > arr[max_idx]) {
                max_idx = j; // Update index of the new maximum element
            }
        }

        // Swap if the maximum element found is not already in the correct position
        if (max_idx != i) {
            swap(arr, i, max_idx); // Swap elements using the separate swap function
        }

        // Print intermediate array state after placing the i-th largest element
        printf("After pass %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() {
    int originalArr[] = {64, 25, 12, 22, 11}; //
    // Calculate total number of elements in the array
    int n = sizeof(originalArr) / sizeof(originalArr[0]); 

    // Working array used to run sorts without losing original input
    int workArr[5];

    printf("================ ASCENDING SORT ================\n");
    copyArray(originalArr, workArr, n); // Copy original values into working array
    printf("Original array: ");
    printArray(workArr, n);

    // Reset metric counters before starting ascending sort
    comparisons = 0;
    shifts = 0;

    // Execute ascending selection sort
    selectionSortAscending(workArr, n);

    printf("\nFinal Sorted array (Ascending): ");
    printArray(workArr, n);
    printf("Number of comparisons: %lld\n", comparisons);
    printf("Number of shifts:      %lld\n", shifts);


    printf("\n================ DESCENDING SORT ================\n");
    copyArray(originalArr, workArr, n); // Reset working array back to original values
    printf("Original array: ");
    printArray(workArr, n);

    // Reset metric counters before starting descending sort
    comparisons = 0;
    shifts = 0;

    // Execute descending selection sort
    selectionSortDescending(workArr, n);

    // Print final sorted array and metrics
    printf("\nFinal Sorted array (Descending): ");
    printArray(workArr, n);
    printf("Number of comparisons: %lld\n", comparisons);
    printf("Number of shifts:      %lld\n", shifts);

    return 0; 
}