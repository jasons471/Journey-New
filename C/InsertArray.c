#include <stdio.h>

// Function Prototypes
void Read_Array(int arr[], int n);
void Display_Array(int arr[], int n);
int Insert_Element(int arr[], int *n);

int main() {
    int i, n, arr[20];

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // Call function to read array from user
    Read_Array(arr, n);

    // Call function to display array elements
    printf("\nBefore insertion:");
    Display_Array(arr, n);

    // Call function to insert an element at a specific position
    // We pass the address of n (&n) so the function can update the size
    n = Insert_Element(arr, &n);

    // Display the array after insertion
    printf("\nThe array after insertion of %d is: ", n);
    Display_Array(arr, n);

    return 0;
}

// --- Function Definitions ---

// Function to read array elements from the user
void Read_Array(int arr[], int n) {
    int i; // initialization variable
    for (i = 0; i < n; i++) {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void Display_Array(int arr[], int n) {
    int i;
    printf("\nThe elements in the array are: ");
    for (i = 0; i < n; i++) {
        printf("\t %d", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at any position
int Insert_Element(int arr[], int *n) {
    int num, pos, i;

    printf("\nEnter number to be inserted: ");
    scanf("%d", &num);

    printf("\nEnter the position at which the number has to be added: ");
    scanf("%d", &pos);

    /* Shift elements to the right to make space for the new element 
       Start from last and move backward until position */
    for (i = *n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element at the specified position
    arr[pos] = num;

    // Increase array size by 1
    *n = *n + 1;

    // Use pointer since 'n' is passed by reference
    // Return new 'n' to main
    return *n;
}