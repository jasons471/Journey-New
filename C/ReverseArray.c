#include <stdio.h>
void Read_Array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        fflush(stdout); 
        // Ensure the prompt is printed before waiting for input
    // Error handling for invalid input can be added here if needed
        while (scanf("%d", &arr[i]) != 1) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter an integer for arr[%d]: ", i);
        }
    }
}
// Function to reverse array in place
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1; 
    // Initialize start and end indices to the first and last elements of the array
    while (start < end) {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; // Move towards the middle of the array
        end--; // Move towards the middle of the array
    }
}
void Display_Array(int arr[], int n) {
    int i;
    printf("\nThe elements in the array are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{
int i, n, arr[20];
printf("Enter number of elements in the array: ");
scanf("%d", &n);
Read_Array(arr, n);
printf("\nBefore reversing:");
Display_Array(arr, n);
reverseArray(arr, n);
printf("\nThe reversed array is: ");
Display_Array(arr, n);
    return 0;
}