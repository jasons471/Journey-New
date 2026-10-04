#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
}
void insertionSort(int arr[], int n) {
    int comp = 0, shft = 0;
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 ) {
            comp++;
            if (arr[j]<temp){
                arr[j + 1] = arr[j];
                shft++; 
                 j = j - 1;   
            }
            else{
                break;
            }
                     
        }
        arr[j + 1] = temp;
        cout<< "Array after insertion "<< i << ": ";
        printArray(arr, n);
        cout<<endl;
    }
    cout<<"Number of comparisons: "<<comp<<endl;
    cout<<"Number of shifts: "<<shft<<endl;
}


int main() {
int n;
    cout << "Enter number of elements (1-100): ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " integers (-1000 to 1000): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, n); 
    cout << "Final sorted array (descending order): ";
    printArray(arr, n); 
    return 0;
}