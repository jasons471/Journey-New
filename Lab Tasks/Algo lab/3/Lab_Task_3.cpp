#include <bits/stdc++.h>
using namespace std;

int stepCounter = 1;

void printSubarray(int arr[], int start, int end) {
    cout << "[";
    for (int i = start; i <= end; i++) {
        cout << arr[i];
        if (i < end) {
            cout << " ";
        }
    }
    cout << "]";
}

void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int lb, int ub) {
    cout << "Partition step " << stepCounter++ << "\n";
    cout << "Current subarray (indices " << lb << " to " << ub << "): ";
    printSubarray(arr, lb, ub);
    cout << "\n";

    int pivot = arr[ub];
    int initial_pivot_index = ub;
    cout << "Selected pivot: " << pivot << ", initial index: " << initial_pivot_index << "\n";

    int i = lb;
    int j = ub;

    while (i < j) {
        while (i <= ub && arr[i] < pivot) {
            i++;
        }
        while (j >= lb && arr[j] >= pivot) {
            j--;
        }
        if (i < j) {
            swapElements(arr[i], arr[j]);
        }
    }
    swapElements(arr[i], arr[ub]);
    int final_pivot_index = i;

    cout << "Subarray after partitioning: ";
    printSubarray(arr, lb, ub);
    cout << "\n";

    if (final_pivot_index - 1 >= lb) {
        cout << "Left subarray (indices " << lb << " to " << final_pivot_index - 1 << "): ";
        printSubarray(arr, lb, final_pivot_index - 1);
        cout << "\n";
    } else {
        cout << "Left subarray: [empty]\n";
    }

    cout << "Pivot: " << pivot << ", final index: " << final_pivot_index << "\n";

    if (final_pivot_index + 1 <= ub) {
        cout << "Right subarray (indices " << final_pivot_index + 1 << " to " << ub << "): ";
        printSubarray(arr, final_pivot_index + 1, ub);
        cout << "\n";
    } else {
        cout << "Right subarray: [empty]\n";
    }

    return final_pivot_index;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int pIndex = partition(arr, lb, ub);
        quickSort(arr, lb, pIndex - 1);
        quickSort(arr, pIndex + 1, ub);
    }
}

int main() {
    int n;

    cout << "Enter the number of integers (1 to 100): ";
    if (!(cin >> n) || n < 1 || n > 100) {
        cout << "Invalid input. n must be between 1 and 100.\n";
        return 0;
    }

    int arr[100];

    cout << "Enter " << n << " integers separated by spaces: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printSubarray(arr, 0, n - 1);
    cout << "\n";

    quickSort(arr, 0, n - 1);

    cout << "Final sorted array in ascending order: ";
    printSubarray(arr, 0, n - 1);
    cout << "\n";

    return 0;
}