#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void primsMST(int vertices, int graph[10][10], const string labels[]) {
    vector<int> key(vertices, INT_MAX);    // To store the minimum weight edge for each vertex
    vector<bool> inMST(vertices, false);   // To track vertices included in MST
    vector<int> parent(vertices, -1);     // To store the MST structure

    key[0] = 0; // Start with the first vertex

    for (int count = 0; count < vertices - 1; ++count) {
        // Find the vertex with the minimum key value that is not yet included in MST
        int minKey = INT_MAX, u;

        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true; // Include the vertex in MST

        // Update key and parent for the adjacent vertices of the chosen vertex
        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    cout << "Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (int i = 1; i < vertices; ++i) {
        cout << labels[parent[i]] << " - " << labels[i] << " : " << graph[parent[i]][i] << "\n";
        totalWeight += graph[parent[i]][i];
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";
}

int main() {
    const int vertices = 10;
    const string labels[] = {"H1", "H2", "H3", "H4", "R1", "R2", "R3", "C1", "I1", "T1"};
    int distanceMatrix[vertices][vertices] = {
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

    primsMST(vertices, distanceMatrix, labels);

    return 0;
}
