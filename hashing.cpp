#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Hashing {
private:
    unordered_map<string, int> distanceTable;

public:
    // Function to insert a distance between two nodes
    void insertDistance(const string& node1, const string& node2, int distance) {
        string key = node1 + "-" + node2;
        distanceTable[key] = distance;

        // Since the graph is undirected, also insert the reverse distance
        string reverseKey = node2 + "-" + node1;
        distanceTable[reverseKey] = distance;
    }

    // Function to get the distance between two nodes
    int getDistance(const string& node1, const string& node2) {
        string key = node1 + "-" + node2;
        if (distanceTable.find(key) != distanceTable.end()) {
            return distanceTable[key];
        } else {
            return -1; // Return -1 if the distance doesn't exist
        }
    }

    // Function to display all distances
    void displayDistances() {
        for (const auto& pair : distanceTable) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    // Distance matrix (graph)
    string locations[] = {"H1", "H2", "H3", "H4", "R1", "R2", "R3", "C1", "I1", "T1"};
    int n = sizeof(locations) / sizeof(locations[0]);

    int dist[10][10] = {
        {0, 8, 12, 15, 10, 20, 25, 5, 18, 30},  // H1
        {8, 0, 10, 13, 12, 15, 18, 10, 25, 22},  // H2
        {12, 10, 0, 9, 22, 18, 20, 15, 8, 28},  // H3
        {15, 13, 9, 0, 18, 30, 25, 20, 15, 35},  // H4
        {10, 12, 22, 18, 0, 8, 10, 12, 20, 25},  // R1
        {20, 15, 18, 30, 8, 0, 5, 18, 22, 15},  // R2
        {25, 18, 20, 25, 10, 5, 0, 22, 25, 12},  // R3
        {5, 10, 15, 20, 12, 18, 22, 0, 12, 28},  // C1
        {18, 25, 8, 15, 20, 22, 25, 12, 0, 10},  // I1
        {30, 22, 28, 35, 25, 15, 12, 28, 10, 0}  // T1
    };

    Hashing hash;

    // Insert distances into the hash table
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            hash.insertDistance(locations[i], locations[j], dist[i][j]);
        }
    }

    // Display all distances stored in the hash table
    cout << "Distances between locations:" << endl;
    hash.displayDistances();

    // Example: Get the distance between two nodes
    cout << "\nDistance between H1 and H2: " << hash.getDistance("H1", "H2") << endl;
    cout << "Distance between R2 and C1: " << hash.getDistance("R2", "C1") << endl;

    return 0;
}
