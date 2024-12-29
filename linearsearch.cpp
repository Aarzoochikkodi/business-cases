#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {0, 8, 12, 15, 10, 20, 25, 5, 18, 30,
                 8, 0, 10, 13, 12, 15, 18, 10, 25, 22,
                 12, 10, 0, 9, 22, 18, 20, 15, 8, 28,
                 15, 13, 9, 0, 18, 30, 25, 20, 15, 35,
                 10, 12, 22, 18, 0, 8, 10, 12, 20, 25,
                 20, 15, 18, 30, 8, 0, 5, 18, 22, 15,
                 25, 18, 20, 25, 10, 5, 0, 22, 25, 12,
                 5, 10, 15, 20, 12, 18, 22, 0, 12, 28,
                 18, 25, 8, 15, 20, 22, 25, 12, 0, 10,
                 30, 22, 28, 35, 25, 15, 12, 28, 10, 0};

    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
