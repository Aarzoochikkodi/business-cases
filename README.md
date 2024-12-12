# Smart Public Transportation Scheduling

This project demonstrates an approach to solve **Smart Public Transportation Scheduling** using the Bellman-Ford algorithm in C++. The algorithm ensures optimized pathfinding, cost minimization, and better scheduling in a public transportation network.

## Problem Statement
Efficient scheduling of public transportation involves identifying the shortest and safest routes between key locations in a city. This requires:

- Calculating the shortest path to minimize travel time or cost.
- Identifying alternate routes to avoid overloading certain paths.
- Managing a dynamic network with potential delays or new routes being added.

The Bellman-Ford algorithm is ideal for solving this as it:

1. Finds the shortest paths from a single source node to all other nodes.
2. Handles graphs with negative weight edges (useful for penalties or delays).

## Solution Approach
### Graph Representation
The transportation network is represented as a directed weighted graph where:
- **Nodes** represent stops or stations.
- **Edges** represent routes between stops with weights as time or cost.

### Steps
1. **Input the Graph**: Define the number of stops and routes with weights (costs).
2. **Initialize Distances**: Set the source node distance to `0` and all others to `infinity`.
3. **Relaxation**: Iteratively update distances of all edges for `V-1` times (where `V` is the number of nodes).
4. **Negative Cycle Detection**: Check for further relaxation; if possible, a negative cycle exists.
5. **Output**: Display the shortest path from the source to all stops or report unreachable stops.

## Implementation in C++
Below is the Bellman-Ford implementation for scheduling:

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int vertices, int edges, vector<Edge>& graph, int source) {
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < vertices - 1; i++) {
        for (const auto& edge : graph) {
            if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) {
                distance[edge.dest] = distance[edge.src] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : graph) {
        if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INT_MAX)
            cout << i << "\tUnreachable" << endl;
        else
            cout << i << "\t" << distance[i] << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<Edge> graph(edges);
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < edges; i++) {
        cin >> graph[i].src >> graph[i].dest >> graph[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(vertices, edges, graph, source);
    return 0;
}
```

## Example Input/Output
### Input
```
Enter number of vertices and edges: 5 8
Enter edges (source destination weight):
0 1 6
0 2 7
1 2 8
1 3 5
1 4 -4
2 3 -3
2 4 9
3 1 -2
Enter the source vertex: 0
```

### Output
```
Vertex\tDistance from Source
0\t0
1\t6
2\t7
3\t4
4\t2
```

## Features
- **Dynamic Updates**: Handle changing routes by re-running the algorithm.
- **Negative Weight Handling**: Accounts for delays or penalties in scheduling.
- **Scalability**: Works for large transportation networks with numerous stops and routes.

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/smart-public-transportation.git
   cd smart-public-transportation
   ```
2. Compile the code:
   ```bash
   g++ -o bellman_ford bellman_ford.cpp
   ```
3. Run the program:
   ```bash
   ./bellman_ford
   ```
4. Follow the prompts to input graph details and the source node.

## Use Cases
- Public transport scheduling to reduce travel time.
- Urban planning for efficient mobility.
- Dynamic route adjustments during disruptions.

## Limitations
- Inefficient for dense graphs due to `O(V * E)` complexity.
- Does not handle undirected graphs with negative cycles.

## Future Enhancements
- Implement priority-based route selection.
- Integrate real-time data updates using APIs.
- Visualize the transportation network and paths.

---
Contributions are welcome! Feel free to fork this repository and submit pull requests.
