#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays: arr[left..mid] and arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int l1 = mid - left + 1; // Length of left temp array
    int r1 = right - mid;    // Length of right temp array

    // Create temporary arrays
    int L[l1], R[r1];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < l1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < r1; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;    // Initial index of first subarray (L)
    j = 0;    // Initial index of second subarray (R)
    k = left; // Initial index of merged subarray (arr)

    while (i < l1 && j < r1) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < l1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < r1) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function that implements Merge Sort (Divide and Conquer)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point to divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function defined AFTER all helper functions
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("\nSorted array:\n");
    printArray(arr, size);

    return 0;
}