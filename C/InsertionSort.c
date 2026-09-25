#include <stdio.h> 
// Function to perform Insertion Sort on an array
void insertionSort(int arr[], int n) {
    // Loop through the array starting from the second element (index 1)
    for (int i = 1; i < n; i++) {
        // Pick the current element to be inserted into the sorted portion
        int key = arr[i];
        
        // Initialize 'j' to point to the last element of the sorted sub-array
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than 'key'
        // one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift the larger element to the right
            j = j - 1;           // Move one step left in the sorted portion
        }
        
        // Place the 'key' at its correct position in the sorted sub-array
        arr[j + 1] = key;
    }
}

// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Print each element followed by a space
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate total number of elements in the array
    printf("Original array: ");
    printArray(arr, n); 
    insertionSort(arr, n); 
    printf("Sorted array: ");
    printArray(arr, n); 

    return 0; 
}