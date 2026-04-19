#include <stdio.h>
void bubbleSortAscending(int arr[], int n) {
    int i, j, temp;
    // Purpose: Repeat passes to move largest element to the end
    for (i = 0; i < n - 1; i++) {
        // Purpose: Compare adjacent elements in each pass
        for (j = 0; j < n - i - 1; j++) {
            // Purpose: Swap if elements are in wrong order
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void bubbleSortDescending(int arr[], int n) {
    int i, j, temp;
    // Purpose: Repeat passes to move smallest element to the end
    for (i = 0; i < n - 1; i++) {
        // Purpose: Compare adjacent elements in each pass
        for (j = 0; j < n - i - 1; j++) {
            // Purpose: Swap if elements are in wrong order (for descending)
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    printArray(arr, n);
    bubbleSortAscending(arr, n);
    printf("Sorted array (ascending): ");
    printArray(arr, n);
    bubbleSortDescending(arr, n);
    printf("Sorted array (descending): ");
    printArray(arr, n);

    return 0;
}