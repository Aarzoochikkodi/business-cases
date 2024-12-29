#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> leftArr(n1), rightArr(n2);
    
    for (int i = 0; i < n1; i++) 
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) 
        rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<vector<int>> matrix = {
        {0, 8, 12, 15, 10, 20, 25, 5, 18, 30},
        {8, 0, 10, 13, 12, 15, 18, 10, 25, 22},
        {12, 10, 0, 9, 22, 18, 20, 15, 8, 28},
        {15, 13, 9, 0, 18, 30, 25, 20, 15, 35},
        {10, 12, 22, 18, 0, 8, 10, 12, 20, 25},
        {20, 15, 18, 30, 8, 0, 5, 18, 22, 15},
        {25, 18, 20, 25, 10, 5, 0, 22, 25, 12},
        {5, 10, 15, 20, 12, 18, 22, 0, 12, 28},
        {18, 25, 8, 15, 20, 22, 25, 12, 0, 10},
        {30, 22, 28, 35, 25, 15, 12, 28, 10, 0}
    };

    // Flatten the matrix into a 1D array
    vector<int> flattened;
    for (const auto& row : matrix) {
        for (int num : row) {
            flattened.push_back(num);
        }
    }

    // Apply Merge Sort on the 1D array
    mergeSort(flattened, 0, flattened.size() - 1);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int num : flattened) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
