#include <stdio.h>
// Function to input elements into the array
void Input_Array(int arr[], int n) {
    int i; //
    for (i = 0; i < n; i++) { //
        printf("\n arr[%d] = ", i); //
        scanf("%d", &arr[i]); //
    }
} //

// Function to delete an element at a specific position
int Delete_Element(int arr[], int n, int pos) {
    int i; //
    // Shift elements to the left to overwrite the element at 'pos'
    for (i = pos; i < n - 1; i++) { //
        arr[i] = arr[i + 1]; //
    }
    n = n - 1; // Decrease the array size
    return n; // Return the new size
} //

// Function to display array elements
void Display_Array(int arr[], int n) {
    int i; //
    printf("\n The array after deletion is: \n"); //
    for (i = 0; i < n; i++) { //
        printf("\n arr[%d] = %d", i, arr[i]); //
    }
} //

int main() {
    int i, n, pos, arr[10]; //

    printf("\n Enter number of elements: "); //
    scanf("%d", &n); //

    // Fill the array
    Input_Array(arr, n); //

    printf("\n Enter delete position: "); //
    scanf("%d", &pos); //

    // Perform deletion and update size n
    n = Delete_Element(arr, n, pos); //

    // Show result
    Display_Array(arr, n); //

    return 0; //
}