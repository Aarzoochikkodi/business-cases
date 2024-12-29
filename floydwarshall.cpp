#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void floydWarshall(int vertices, int graph[10][10], const string labels[]) {
    int dist[10][10];

    // Initialize the distance matrix with the input graph
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            } else {
                dist[i][j] = INT_MAX;
            }
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < vertices; ++k) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << "\n";
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

    floydWarshall(vertices, distanceMatrix, labels);

    return 0;
}
