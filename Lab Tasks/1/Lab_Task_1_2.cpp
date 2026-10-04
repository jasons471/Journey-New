#include <bits/stdc++.h>
using namespace std;
void printArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}
void selectionSort(char arr[], int n) {
    int i, j, min, temp;
    int comp = 0, swap = 0;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            comp++;
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = arr[i];        
            arr[i] = arr[min]; 
            arr[min] = temp;
            swap++;
             cout << "Array after swaps " << swap << ": ";
             printArray(arr, n);
        }
    }
    cout<<"Number of element comparisons: "<<comp<<endl;
    cout<<"Number of swaps: "<<swap<<endl;
}
int main() {
    int n;
    cout<< "Enter the number of characters (1-100): ";
    cin >> n;
    char arr[100];
    cout << "Enter " << n << " characters: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, n); 
    cout << "Final sorted array: ";
    printArray(arr, n); 
    return 0; 
}