#include <stdio.h> 

// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped; // Flag to check if any swapping occurred in a pass

    // Loop through the array for (n - 1) passes
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Reset swap flag at the start of each pass

        // Last 'i' elements are already in place, so inner loop stops early
        for (j = 0; j < n - i - 1; j++) {
            
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                
                // Swap arr[j] and arr[j + 1] if they are in the wrong order
                temp = arr[j];        // Store left element in temporary variable
                arr[j] = arr[j + 1];  // Move smaller right element to the left
                arr[j + 1] = temp;   // Move larger left element to the right

                swapped = 1; // Mark that a swap occurred in this pass
            }
        }

        // Optimization: If no two elements were swapped, array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Helper function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Print each element followed by a space
    }
    printf("\n"); // Print a new line after the array is displayed
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr) / sizeof(arr[0]);     // Calculate total number of elements
    printf("Original array: ");
    printArray(arr, n); 
    bubbleSort(arr, n); 
    printf("Sorted array:   ");
    printArray(arr, n);
    
    return 0;
}