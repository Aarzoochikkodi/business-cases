#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Each element is its own parent initially
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    // Distance matrix (flattened)
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

    int n = dist.size();  // Number of locations (nodes)
    UnionFind uf(n);

    // Threshold distance to connect locations (edges)
    int threshold = 15;

    // Perform Union-Find for each pair of locations with distance <= threshold
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist[i][j] <= threshold) {
                uf.unionSets(i, j);
            }
        }
    }

    // Check connectivity between some locations
    cout << "Are H1 and H2 connected? " << (uf.connected(0, 1) ? "Yes" : "No") << endl;
    cout << "Are R1 and C1 connected? " << (uf.connected(4, 7) ? "Yes" : "No") << endl;
    cout << "Are I1 and T1 connected? " << (uf.connected(8, 9) ? "Yes" : "No") << endl;

    return 0;
}
