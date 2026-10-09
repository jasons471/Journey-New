#include <stdio.h>  

// Function to swap two elements in an array using their indices
void swap(int arr[], int i, int j) {
    // Store value at index i in a temporary variable
    int temp = arr[i];
    // Assign value from index j to index i
    arr[i] = arr[j];
    // Assign stored temporary value to index j
    arr[j] = temp;
}

// Function to partition the array around a pivot element (Lomuto partition scheme)
int partition(int arr[], int low, int high) {
    // Select the last element of the current segment as the pivot
    int pivot = arr[high];
    
    // Index of the smaller element; tracks boundary for elements <= pivot
    int i = (low - 1);

    // Iterate through array segment from index 'low' up to 'high - 1'
    for (int j = low; j < high; j++) {
        // Check if current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            // Increment the boundary index
            i++;
            // Swap elements by passing the array and the two indices directly
            swap(arr, i, j);
        }
    }

    // Place the pivot in its correct sorted position
    swap(arr, i + 1, high);

    // Return the final index where the pivot element is now located
    return (i + 1);
}

// Recursive function to perform Quick Sort on an array segment [low, high]
void quickSort(int arr[], int low, int high) {
    // Base condition: execute only if segment has at least two elements
    if (low < high) {
        // Partition array and retrieve partitioning index of pivot
        int pi = partition(arr, low, high);

        // Recursively sort sub-array before the pivot
        quickSort(arr, low, pi - 1);

        // Recursively sort sub-array after the pivot
        quickSort(arr, pi + 1, high);
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
    int arr[] = {24, 9, 29, 14, 19, 27};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}