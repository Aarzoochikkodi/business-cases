# Business Cases - SDG Mapping

This document outlines three key business cases with their approaches to solving problems related to sustainable cities, water management, and public transportation. Each case is designed to address specific SDGs and provide efficient solutions to urban challenges. The code implementations for each case are also included for further exploration.

---

## 1. Optimal Road Network Design

**Relevant SDG:**  
Sustainable Cities and Communities (SDG 11)

**Target:**  
11.2 - Provide access to safe, affordable, and sustainable transport systems for all.

**Indicator:**  
11.2.1 - Proportion of population with convenient access to public transport.

### Approach to Solve the Problem

The goal of this business case is to optimize the road network for efficient transportation. By using **Dijkstra's Algorithm**, we can find the shortest path between different nodes (locations) in the road network. This helps reduce travel time and fuel consumption, ensuring faster and more efficient movement within the city.

- The city's road network is represented as a graph, with intersections as nodes and roads as edges. 
- The Dijkstra algorithm calculates the shortest path from a source location to all other nodes, helping design the best routes for public transportation, minimizing congestion and optimizing traffic flow.
- This approach will help reduce fuel consumption, travel time, and ultimately contribute to cleaner and more sustainable cities.

#### C++ Code for Optimal Road Network Design:


```cpp
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Edge {
    int destination;
    int weight;
};

struct Graph {
    vector<vector<Edge>> adjList;
    
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
};

vector<int> dijkstra(const Graph& graph, int start) {
    int n = graph.adjList.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (const Edge& edge : graph.adjList[u]) {
            int v = edge.destination;
            int weight = edge.weight;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    Graph graph;
    graph.adjList.resize(5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 4, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(4, 1, 3);
    graph.addEdge(4, 2, 9);
    graph.addEdge(2, 3, 4);
    
    vector<int> distances = dijkstra(graph, 0);
    
    for (int i = 0; i < distances.size(); i++) {
        cout << "Distance from 0 to " << i << " is " << distances[i] << endl;
    }
    
    return 0;
}

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
Vertex	Distance from Source
0	0
1	6
2	7
3	4
4	2
```

## Features
- **Dynamic Updates**: Handle changing routes by re-running the algorithm.
- **Negative Weight Handling**: Accounts for delays or penalties in scheduling.
- **Scalability**: Works for large transportation networks with numerous stops and routes.


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

