#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap;  // By default, max-heap in C++

    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(15);

    cout << "Priority Queue (Max Heap): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap

    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(15);

    cout << "Priority Queue (Min Heap): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
