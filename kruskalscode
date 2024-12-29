#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Edge {
    int src, dest, weight;
};

// Comparator function to sort edges based on weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (DSU) structure for Union-Find
class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskalsMST(int vertices, vector<Edge>& edges, const string labels[]) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(vertices);
    vector<Edge> mst;
    int mstWeight = 0;

    for (const auto& edge : edges) {
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            mst.push_back(edge);
            mstWeight += edge.weight;
            dsu.unite(edge.src, edge.dest);
        }
    }

    // Print MST
    cout << "Minimum Spanning Tree:\n";
    for (const auto& edge : mst) {
        cout << labels[edge.src] << " - " << labels[edge.dest] << " : " << edge.weight << "\n";
    }
    cout << "Total Weight of MST: " << mstWeight << "\n";
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

    vector<Edge> edges;

    // Convert the distance matrix into a list of edges
    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            if (distanceMatrix[i][j] != 0) {
                edges.push_back({i, j, distanceMatrix[i][j]});
            }
        }
    }

    kruskalsMST(vertices, edges, labels);

    return 0;
}
