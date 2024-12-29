#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Target found, return the index
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Search in the right half
        }
        else {
            right = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Target not found
}

int main() {
    vector<int> sortedArr = {0, 0, 0, 0, 5, 5, 5, 8, 8, 8, 9, 10, 10, 10, 12, 12, 12, 13, 15, 15, 15, 18, 18, 18, 18, 20, 20, 20, 22, 22, 22, 25, 25, 25, 28, 28, 30, 30, 35};

    int target = 18;  // Example target to search
    int result = binarySearch(sortedArr, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found" << endl;
    }

    return 0;
}
