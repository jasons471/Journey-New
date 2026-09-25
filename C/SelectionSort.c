#include <stdio.h> 

// Function to perform Selection Sort on an array
void selectionSort(int arr[], int n) {
    int i, j, min, temp;

    // Loop through the entire array up to the second-to-last element
    for (i = 0; i < n - 1; i++) {
        
        // Assume the current position 'i' holds the minimum element
        min = i;

        // Loop through the unsorted part of the array to find the true minimum
        for (j = i + 1; j < n; j++) {
            
            // Check if the current element is smaller than our recorded minimum
            if (arr[j] < arr[min]) {
                min = j; // Update the index of the new minimum element
            }
        }

        // Swap() if the minimum element found is not already in the correct position
        if (min != i) {
            temp = arr[i];        // Store original element in a temporary variable
            arr[i] = arr[min]; // Place the minimum element in its correct sorted spot
            arr[min] = temp;  // Move the original element to the minimum's previous position
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate total number of elements in the array
    printf("Original array: ");
    printArray(arr, n); 
    selectionSort(arr, n); 
    printf("Sorted array:   ");
    printArray(arr, n); 
    
    return 0; 
}