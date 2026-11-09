#include <stdio.h> 

// Global tracking variables to eliminate all pointer arguments
long long comparisons = 0;
long long shifts = 0;

// Function to print a sub-array formatted with brackets: [x y z]
void printSubArray(int arr[], int start, int end) {
    // Print opening bracket
    printf("[");
    // Iterate from start to end index
    for (int i = start; i <= end; i++) {
        // Print value with trailing space if not the final element
        if (i < end) {
            printf("%d ", arr[i]);
        } else {
            // Print final element without trailing space
            printf("%d", arr[i]);
        }
    }
    // Print closing bracket
    printf("]");
}

// Function to print the entire array with space separation
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Merge function for ASCENDING order 
void mergeAscending(int arr[], int lb, int mid, int ub) {
    // Size of left portion
    int l1 = mid - lb + 1;
    // Size of right portion
    int r1 = ub - mid;

    // Temporary local arrays
    int L[l1];
    int R[r1];

    // Populate temporary left array
    for (int i = 0; i < l1; i++) {
        // Copy item from main array
        L[i] = arr[lb + i];
        // Increment shifts counter
        shifts++;
    }

    // Populate temporary right array
    for (int j = 0; j < r1; j++) {
        // Copy item from main array
        R[j] = arr[mid + 1 + j];
        // Increment shifts counter
        shifts++;
    }

    // Display sub-arrays being merged
    printf("Merging: ");
    printSubArray(arr, lb, mid);
    printf(" + ");
    printSubArray(arr, mid + 1, ub);
    printf("\n");

    // Sub-array indexes
    int i = 0;
    int j = 0;
    int k = lb;

    // Merge in ascending order
    while (i < l1 && j < r1) {
        // Increment comparison counter
        comparisons++;

        // Check for smaller or equal element
        if (L[i] <= R[j]) {
            // Place from left array
            arr[k] = L[i];
            // Move index forward
            i++;
        } else {
            // Place from right array
            arr[k] = R[j];
            // Move index forward
            j++;
        }
        // Increment shifts counter
        shifts++;
        // Move destination index
        k++;
    }

    // Copy remaining items from left sub-array
    while (i < l1) {
        // Assign item
        arr[k] = L[i];
        // Advance left index
        i++;
        // Advance main index
        k++;
        // Increment shifts counter
        shifts++;
    }

    // Copy remaining items from right sub-array
    while (j < r1) {
        // Assign item
        arr[k] = R[j];
        // Advance right index
        j++;
        // Advance main index
        k++;
        // Increment shifts counter
        shifts++;
    }

    // Display intermediate merged result
    printf("Result:  ");
    printSubArray(arr, lb, ub);
    printf("\n\n");
}

// Recursive Merge Sort function for ASCENDING order 
void mergeSortAscending(int arr[], int lb, int ub) {
    // Only continue if segment has 2 or more elements
    if (lb < ub) {
        // Calculate middle point
        int mid = lb + (ub - lb) / 2;

        // Sort left partition
        mergeSortAscending(arr, lb, mid);

        // Sort right partition
        mergeSortAscending(arr, mid + 1, ub);

        // Merge both partitions in ascending order
        mergeAscending(arr, lb, mid, ub);
    }
}

// Merge function for DESCENDING order 
void mergeDescending(int arr[], int lb, int mid, int ub) {
    // Size of left portion
    int l1 = mid - lb + 1;
    // Size of right portion
    int r1 = ub - mid;

    // Temporary local arrays
    int L[l1];
    int R[r1];

    // Populate temporary left array
    for (int i = 0; i < l1; i++) {
        // Copy item from main array
        L[i] = arr[lb + i];
        // Increment shifts counter
        shifts++;
    }

    // Populate temporary right array
    for (int j = 0; j < r1; j++) {
        // Copy item from main array
        R[j] = arr[mid + 1 + j];
        // Increment shifts counter
        shifts++;
    }

    // Display sub-arrays being merged
    printf("Merging: ");
    printSubArray(arr, lb, mid);
    printf(" + ");
    printSubArray(arr, mid + 1, ub);
    printf("\n");

    // Sub-array indexes
    int i = 0;
    int j = 0;
    int k = lb;

    // Merge in descending order
    while (i < l1 && j < r1) {
        // Increment comparison counter
        comparisons++;

        // Check for larger or equal element
        if (L[i] >= R[j]) {
            // Place from left array
            arr[k] = L[i];
            // Move index forward
            i++;
        } else {
            // Place from right array
            arr[k] = R[j];
            // Move index forward
            j++;
        }
        // Increment shifts counter
        shifts++;
        // Move destination index
        k++;
    }

    // Copy remaining items from left sub-array
    while (i < l1) {
        // Assign item
        arr[k] = L[i];
        // Advance left index
        i++;
        // Advance main index
        k++;
        // Increment shifts counter
        shifts++;
    }

    // Copy remaining items from right sub-array
    while (j < r1) {
        // Assign item
        arr[k] = R[j];
        // Advance right index
        j++;
        // Advance main index
        k++;
        // Increment shifts counter
        shifts++;
    }

    // Display intermediate merged result
    printf("Result:  ");
    printSubArray(arr, lb, ub);
    printf("\n\n");
}

// Recursive Merge Sort function for DESCENDING order 
void mergeSortDescending(int arr[], int lb, int ub) {
    // Only continue if segment has 2 or more elements
    if (lb < ub) {
        // Calculate middle point
        int mid = lb + (ub - lb) / 2;

        // Sort left partition
        mergeSortDescending(arr, lb, mid);

        // Sort right partition
        mergeSortDescending(arr, mid + 1, ub);

        // Merge both partitions in descending order
        mergeDescending(arr, lb, mid, ub);
    }
}

int main() {
    // Hardcoded example array to sort in ascending order
    int arrAsc[] = {38, 27, 43, 3, 9, 82};
    // Hardcoded example array to sort in descending order
    int arrDesc[] = {38, 27, 43, 3, 9, 82};

    // Calculate total number of elements
    int n = sizeof(arrAsc) / sizeof(arrAsc[0]);

    printf("Original array: ");
    printArray(arrAsc, n);
    printf("\n");

    // Reset counters before ascending execution
    comparisons = 0;
    shifts = 0;

    printf("- - - Merge Sort Steps (Ascending) - - -\n\n");
    mergeSortAscending(arrAsc, 0, n - 1);

    printf("Final sorted array (ascending): ");
    printArray(arrAsc, n);

    // Display comparisons and shifts count
    printf("Number of comparisons: %lld\n", comparisons);
    printf("Number of shifts: %lld\n\n", shifts);

    // Reset counters before descending execution
    comparisons = 0;
    shifts = 0;


    printf("- - - Merge Sort Steps (Descending) - - -\n\n");
    mergeSortDescending(arrDesc, 0, n - 1);

    printf("Final sorted array (descending): ");
    printArray(arrDesc, n);

    printf("Number of comparisons: %lld\n", comparisons);
    printf("Number of shifts: %lld\n", shifts);

    return 0;
}