#include <stdio.h>

// --- FUNCTION PROTOTYPES ---
void Input_Array(int arr[], int n);
void Display_Array(int arr[], int n);
int Delete_Element(int arr[], int n, int pos);
int Linear_Search(int arr[], int n, int x);
int Binary_Search(int arr[], int x, int low, int high);

int main() {
    int n, pos, x, choice, result;
    int arr[20]; // Defined with a standard size

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Initializing the array
    Input_Array(arr, n);

    printf("\nChoose an operation:\n1. Delete Element\n2. Linear Search\n3. Binary Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // --- DELETION LOGIC ---
            printf("\nEnter delete position: ");
            scanf("%d", &pos);
            n = Delete_Element(arr, n, pos);
            Display_Array(arr, n);
            break;

        case 2:
            // --- LINEAR SEARCH LOGIC ---
            printf("\nEnter item to search: ");
            scanf("%d", &x);
            result = Linear_Search(arr, n, x);
            if (result == -1) {
                printf("Not found\n");
            } else {
                printf("Value found at location: %d\n", result);
            }
            break;

        case 3:
            // --- BINARY SEARCH LOGIC ---
            // Note: Binary search requires a sorted array
            printf("\nEnter target item: ");
            scanf("%d", &x);
            // low is 0, high is n-1
            result = Binary_Search(arr, x, 0, n - 1);
            if (result == -1) {
                printf("Element not found\n");
            } else {
                printf("Element found at index %d\n", result);
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}

// --- FUNCTION DEFINITIONS ---

// Deletion: Shift elements left to overwrite the target position
void Input_Array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

int Delete_Element(int arr[], int n, int pos) {
    int i;
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n = n - 1;
    return n;
}

void Display_Array(int arr[], int n) {
    int i;
    printf("\nThe array after deletion is:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

// Linear Search: Check every element sequentially
int Linear_Search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Binary Search: Divide and conquer on a sorted array
int Binary_Search(int arr[], int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}