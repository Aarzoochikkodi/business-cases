#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class BellmanFord {
private:
    int V;  // Number of vertices (locations)
    vector<vector<int>> dist;  // Distance matrix (graph)
    
public:
    BellmanFord(int vertices, const vector<vector<int>>& graph) {
        V = vertices;
        dist = graph;
    }

    void bellmanFord(int src) {
        vector<int> distance(V, INT_MAX);  // Initialize all distances as infinity
        distance[src] = 0;  // Distance to the source is 0

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (int v = 0; v < V; v++) {
                    if (dist[u][v] != 0 && distance[u] != INT_MAX && distance[u] + dist[u][v] < distance[v]) {
                        distance[v] = distance[u] + dist[u][v];
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (dist[u][v] != 0 && distance[u] != INT_MAX && distance[u] + dist[u][v] < distance[v]) {
                    cout << "Graph contains negative weight cycle" << endl;
                    return;
                }
            }
        }

        // Print the shortest distances from source
        cout << "Shortest distances from source (node " << src << "):\n";
        for (int i = 0; i < V; i++) {
            if (distance[i] == INT_MAX) {
                cout << "To node " << i << ": INF\n";
            } else {
                cout << "To node " << i << ": " << distance[i] << endl;
            }
        }
    }
};

int main() {
    // Distance matrix (graph)
    vector<vector<int>> dist = {
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

    int n = dist.size();  // Number of locations (vertices)
    BellmanFord bf(n, dist);

    int source = 0;  // Source node (H1)
    bf.bellmanFord(source);

    return 0;
}
