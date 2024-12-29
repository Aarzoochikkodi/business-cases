#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void bfs(int vertices, vector<int> graph[], int start, const string labels[]) {
    vector<bool> visited(vertices, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from " << labels[start] << ":\n";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << labels[u] << " ";

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

int main() {
    const int vertices = 10;
    const string labels[] = {"H1", "H2", "H3", "H4", "R1", "R2", "R3", "C1", "I1", "T1"};

    vector<int> graph[vertices];

    // Add edges to the adjacency list representation of the graph
    graph[0] = {1, 4, 7}; // H1 connects to H2, R1, C1
    graph[1] = {0, 2, 4}; // H2 connects to H1, H3, R1
    graph[2] = {1, 3, 8}; // H3 connects to H2, H4, I1
    graph[3] = {2, 4, 9}; // H4 connects to H3, R1, T1
    graph[4] = {0, 1, 3, 5}; // R1 connects to H1, H2, H4, R2
    graph[5] = {4, 6}; // R2 connects to R1, R3
    graph[6] = {5, 7, 9}; // R3 connects to R2, C1, T1
    graph[7] = {0, 6, 8}; // C1 connects to H1, R3, I1
    graph[8] = {2, 7, 9}; // I1 connects to H3, C1, T1
    graph[9] = {3, 6, 8}; // T1 connects to H4, R3, I1

    int startVertex = 0; // Starting from H1 (index 0)
    bfs(vertices, graph, startVertex, labels);

    return 0;
}
