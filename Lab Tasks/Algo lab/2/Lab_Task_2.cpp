#include<bits/stdc++.h>
using namespace std; 

bool isVowel(char ch) {
    switch (ch) {
        case 'a': 
        case 'e': 
        case 'i': 
        case 'o': 
        case 'u': 
        case 'A': 
        case 'E': 
        case 'I': 
        case 'O': 
        case 'U': 
            return true; 
        default:
            return false; 
    }
}
void printSubArray(char arr[], int start, int end) {
    cout << "["; 
    
   
    for (int i = start; i <= end; i++) {
        cout << arr[i]; 
        
        
        if (i < end) {
            cout << " ";
        }
    }
    
    cout << "]"; // Print the closing bracket
}

// Function to combine two adjacent sorted subarrays: arr[left..mid] and arr[mid+1..right]
void merge(char arr[], int left, int mid, int right) {
    // Print the merge message displaying both subarrays being merged
    cout << "Merging: ";
    printSubArray(arr, left, mid);      // Display the left sorted subarray
    cout << " + ";
    printSubArray(arr, mid + 1, right);  // Display the right sorted subarray
    cout << "\n";

    char temp[100]; // Temporary raw array used to store the merged sequence
    int i = left;      // Pointer starting at the beginning of the left subarray
    int j = mid + 1;   // Pointer starting at the beginning of the right subarray
    int k = 0;         // Pointer for tracking position in the temporary array

    // Compare characters from both subarrays and insert the smaller one into temp
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) { // If left element is smaller or equal
            temp[k++] = arr[i++]; // Copy character from left subarray and increment both pointers
        } else {                // If right element is smaller
            temp[k++] = arr[j++]; // Copy character from right subarray and increment both pointers
        }
    }

    // Copy any leftover characters from the left subarray into temp
    while (i <= mid) {
        temp[k++] = arr[i++]; // Copy character and advance pointers
    }

    // Copy any leftover characters from the right subarray into temp
    while (j <= right) {
        temp[k++] = arr[j++]; // Copy character and advance pointers
    }

    // Write back the sorted merged characters from temp to the original array
    for (int idx = 0; idx < k; ++idx) {
        arr[left + idx] = temp[idx]; // Overwrite character at original position
    }

    // Output the resulting sorted subarray
    cout << "Result: ";
    printSubArray(arr, left, right); // Print the newly merged subarray slice
    cout << "\n";
}

// Recursive function to split the array down to single elements and merge sort them
void mergeSort(char arr[], int left, int right) {
    if (left >= right) { // Base condition: if subarray has 1 or fewer elements, it is sorted
        return;          // Return to previous recursive call
    }

    int mid = left + (right - left) / 2; // Compute midpoint safely to avoid overflow

    mergeSort(arr, left, mid);      // Recursively divide and sort the left half
    mergeSort(arr, mid + 1, right);  // Recursively divide and sort the right half
    merge(arr, left, mid, right);   // Merge both sorted halves together
}
void displayFullArray(char arr[], int n) {
    for (int i = 0; i < n; i++) { // Loop through all elements in the array
        cout << arr[i];           // Print current character
        if (i < n - 1) {
            cout << " ";          // Space between characters
        }
    }
    cout << "\n"; // Move to next line
}

int main() {
    int n; // Variable to store the number of elements
    cout << "Enter the number of elements (1-100): ";
    cin >> n; // Read total count from the user

    // Check if the number of elements is outside the valid range[cite: 2]
    if (n < 1 || n > 100) {
        cout << "Invalid number of elements." << endl; // Display error message[cite: 3]
        return 0; // Exit the program[cite: 3]
    }

    char arr[100]; // Fixed array to store up to 100 non-vowel characters[cite: 2]
    int count = 0; // Counter for valid characters collected

    cout << "Enter " << n << " non-vowel characters:\n";

    // Loop until we collect exactly n non-vowel characters[cite: 2]
    while (count < n) {
        char ch; // Variable to take each input character
        cin >> ch; // Read character

        // If the character is a vowel, reject it and ask again[cite: 2]
        if (isVowel(ch)) {
            cout << "Vowels are not allowed.\nEnter another character:\n"; // Prompt re-entry[cite: 3]
        } else {
            arr[count] = ch; // Store the valid character in the array
            count++; // Increment the counter
        }
    }

    cout << "\nOriginal array: ";
    displayFullArray(arr, n);
    cout << "\n";

    cout << "Merge Sort Steps\n"; 
    mergeSort(arr, 0, n - 1); 
    cout << "\nFinal sorted array: ";
    displayFullArray(arr, n);
    cout << endl; 

    return 0; 
}