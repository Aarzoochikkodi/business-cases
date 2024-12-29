#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Queue {
private:
    queue<string> q;  // Standard queue from C++ STL
    
public:
    // Function to enqueue an element (location)
    void enqueue(const string& location) {
        q.push(location);
        cout << "Enqueued: " << location << endl;
    }
    
    // Function to dequeue an element (location)
    void dequeue() {
        if (q.empty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Dequeued: " << q.front() << endl;
            q.pop();
        }
    }

    // Function to get the front element of the queue
    string front() {
        if (!q.empty()) {
            return q.front();
        } else {
            return "Queue is empty!";
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    // Locations (nodes)
    string locations[] = {"H1", "H2", "H3", "H4", "R1", "R2", "R3", "C1", "I1", "T1"};
    int n = sizeof(locations) / sizeof(locations[0]);
    
    // Create a queue object
    Queue queue;

    // Enqueue all locations
    for (int i = 0; i < n; i++) {
        queue.enqueue(locations[i]);
    }

    // Dequeue and process the elements in FIFO order
    while (!queue.isEmpty()) {
        string location = queue.front();
        queue.dequeue();
        
        // Simulate distance calculation by printing the current location
        cout << "Processing " << location << " and its neighbors:\n";

        // Example: Distance calculation from the current location to others (can be extended)
        for (int j = 0; j < n; j++) {
            cout << "Distance from " << location << " to " << locations[j] << " is: ";
            // Assume we have a function or matrix to fetch the distance (using static example)
            // You can integrate the distance matrix calculation here
            cout << "N/A (distance matrix can be implemented)" << endl;
        }
        cout << endl;
    }

    return 0;
}
