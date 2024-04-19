#include <iostream>
#include <vector>
using namespace std;

int findMedian(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;

    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);

    return mid;
}

int partition(int arr[], int left, int right) {
    int pivotIndex = findMedian(arr, left, right);
    int pivotValue = arr[pivotIndex];

    swap(arr[pivotIndex], arr[right]);
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivotValue) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[right]);
    return i;
}

// Function to perform quicksort
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);

        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
