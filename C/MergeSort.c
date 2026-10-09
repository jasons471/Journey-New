#include <stdio.h>  
#include <stdlib.h> 

// Function to merge two sorted sub-arrays into a single sorted sub-array
void merge(int arr[], int left, int mid, int right) {
    // Calculate the size of the left sub-array
    int l1 = mid - left + 1;
    // Calculate the size of the right sub-array
    int r1 = right - mid;

    // Dynamically allocate memory for temporary left array
    int *L = (int *)malloc(l1 * sizeof(int));
    // Dynamically allocate memory for temporary right array
    int *R = (int *)malloc(r1 * sizeof(int));

    // Copy data from main array into temporary left array
    for (int i = 0; i < l1; i++) {
        // Offset by 'left' index to get elements from the left partition
        L[i] = arr[left + i];
    }

    // Copy data from main array into temporary right array
    for (int j = 0; j < r1; j++) {
        // Offset by 'mid + 1' index to get elements from the right partition
        R[j] = arr[mid + 1 + j];
    }

    // Initial index of first sub-array
    int i = 0;
    // Initial index of second sub-array
    int j = 0;
    // Initial index of merged sub-array starting at 'left'
    int k = left;

    // Compare elements of both sub-arrays and place the smaller one into arr
    while (i < l1 && j < r1) {
        // Check if the current element in L is smaller or equal to current in R
        if (L[i] <= R[j]) {
            // Assign the smaller element from L to arr
            arr[k] = L[i];
            // Move pointer in L forward
            i++;
        } else {
            // Assign the smaller element from R to arr
            arr[k] = R[j];
            // Move pointer in R forward
            j++;
        }
        // Move pointer in the merged array forward
        k++;
    }

    // Copy any remaining elements of L[] if any are left
    while (i < l1) {
        // Place remaining element into arr
        arr[k] = L[i];
        // Increment pointer for L
        i++;
        // Increment pointer for arr
        k++;
    }

    // Copy any remaining elements of R[] if any are left
    while (j < r1) {
        // Place remaining element into arr
        arr[k] = R[j];
        // Increment pointer for R
        j++;
        // Increment pointer for arr
        k++;
    }

    // Free dynamically allocated memory for L to prevent memory leaks
    free(L);
    // Free dynamically allocated memory for R to prevent memory leaks
    free(R);
}

// Recursive function that implements Merge Sort
void mergeSort(int arr[], int left, int right) {
    // Base condition: continue only if the range contains at least two elements
    if (left < right) {
        // Calculate the midpoint to avoid integer overflow: left + (right - left) / 2
        int mid = left + (right - left) / 2;

        // Recursively sort the left half
        mergeSort(arr, left, mid);

        // Recursively sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves together
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    // Calculate total number of elements: total bytes divided by bytes per element
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}