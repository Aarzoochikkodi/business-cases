#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void dijkstra(int vertices, int graph[10][10], int start, const string labels[]) {
    vector<int> dist(vertices, INT_MAX);  // To store shortest distance from start
    vector<bool> visited(vertices, false); // To track visited vertices

    dist[start] = 0; // Distance to the start vertex is 0

    for (int count = 0; count < vertices - 1; ++count) {
        // Find the vertex with the minimum distance that is not yet visited
        int minDist = INT_MAX, u;

        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        visited[u] = true; // Mark the chosen vertex as visited

        // Update distance value of adjacent vertices
        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from " << labels[start] << ":\n";
    for (int i = 0; i < vertices; ++i) {
        cout << labels[start] << " -> " << labels[i] << " : " << dist[i] << "\n";
    }
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

    int startVertex = 0; // Starting from H1 (index 0)
    dijkstra(vertices, distanceMatrix, startVertex, labels);

    return 0;
}
