#include <stdio.h> 


void printArray(const int arr[], int size) { 
    for (int i = 0; i < size; i++) { 
        printf(" %d", arr[i]); 
    } 
} 

// Function definition for copying array elements from source to destination
void copyArray(const int src[], int dest[], int size) { // Function taking source array, destination array, and size
    for (int i = 0; i < size; i++) { // Loop through array indices up to size
        dest[i] = src[i]; // Copy element at index i from source array to destination array
    } 
} 

// Function definition for Insertion Sort in ASCENDING order with step output and metric tracking
void insertionSortAscending(int arr[], int n) { 
    // n is the number of elements in the array to be sorted
    int comparisons = 0; // Initialize comparison counter to zero
    int shifts = 0; // Initialize shift counter to zero

    for (int i = 1; i < n; i++) { 
        int key = arr[i]; // Store current element as key to be placed in the sorted sub-array
        int j = i - 1; // Set index j to point to the element immediately before key

        while (j >= 0) { // Loop backwards through sorted portion of array
            comparisons++; // Increment comparison counter for each check
            if (arr[j] > key) { // Check if element on left is greater than key (ascending order check)
                arr[j + 1] = arr[j]; // Shift larger element one position to the right
                shifts++; // Increment shift counter
                j--; // Move index j one position to the left
            } 
            else { // Triggered when correct position for key is found
                break; // Exit inner loop as key is greater or equal to arr[j]
            } 
        } 

        arr[j + 1] = key; // Place key into its correct sorted position

        printf("Array after insertion %d:", i); // Print step tracking header
        printArray(arr, n); 
        printf("\n"); 
    } 

    printf("\nNumber of comparisons: %d\n", comparisons); // Display total number of comparisons made
    printf("Number of shifts: %d\n", shifts); // Display total number of shifts performed
    printf("Final sorted array (ascending order):"); 
    printArray(arr, n); 
    printf("\n"); 
} 

// Function definition for Insertion Sort in DESCENDING order with step output and metric tracking
void insertionSortDescending(int arr[], int n) { 
    int comparisons = 0; // Initialize comparison counter to zero
    int shifts = 0; // Initialize shift counter to zero

    for (int i = 1; i < n; i++) { 
        int key = arr[i]; // Store current element as key to be placed in the sorted sub-array
        int j = i - 1; // Set index j to point to the element immediately before key

        while (j >= 0) { // Loop backwards through sorted portion of array
            comparisons++; // Increment comparison counter for each check
            if (arr[j] < key) { // Check if element on left is smaller than key (descending order check)
                arr[j + 1] = arr[j]; // Shift smaller element one position to the right
                shifts++; // Increment shift counter
                j--; // Move index j one position to the left
            } 
            else { // Triggered when correct position for key is found
                break; // Exit inner loop as key is smaller or equal to arr[j]
            } 
        } 

        arr[j + 1] = key; // Place key into its correct sorted position

        printf("Array after insertion %d:", i); 
        printArray(arr, n); 
        printf("\n"); 
    } 

    printf("\nNumber of comparisons: %d\n", comparisons); // Display total number of comparisons 
    printf("Number of shifts: %d\n", shifts); // Display total number of shifts 
    printf("Final sorted array (descending order):"); 
    printArray(arr, n); 
    printf("\n"); 
} 


int main() { 
    int n; 
    int originalArr[100]; 
    int workArr[100]; // Declare arrays to hold original and working copies of the input data

    printf("Enter the number of elements (1 to 100): "); 
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) { // Read and validate array size constraint (1 to 100)
        printf("Invalid number of elements.\n"); 
        return 1; // Exit program with non-zero error status
    } 
    printf("Enter %d integers (-1000 to 1000):\n", n); 
    for (int i = 0; i < n; i++) { 
        if (scanf("%d", &originalArr[i]) != 1 || originalArr[i] < -1000 || originalArr[i] > 1000) { // Read and validate integer value limits (-1000 to 1000)
            printf("Invalid input value.\n"); // Print error message if input element is out of range
            return 1; 
        } 
    }

    printf("\n================ ASCENDING SORT ================\n"); 
    copyArray(originalArr, workArr, n); 
    insertionSortAscending(workArr, n); 

    printf("\n================ DESCENDING SORT ================\n"); 
    copyArray(originalArr, workArr, n); 
    insertionSortDescending(workArr, n); 

    return 0; 
} 