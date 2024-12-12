# Optimal Road Network Design

This project demonstrates an approach to solve *Optimal Road Network Design* using Dijkstra's algorithm in C++. The algorithm is used to find the shortest path between nodes in a graph, ensuring efficient road network design with minimized travel time and costs.

## Problem Statement
Designing an optimal road network involves:

- Determining the shortest and most cost-effective paths between various locations.
- Ensuring connectivity between all nodes in the network.
- Balancing load distribution to prevent congestion on key routes.

Dijkstra's algorithm is ideal for solving this as it:

1. Finds the shortest path from a single source node to all other nodes.
2. Works efficiently for graphs with non-negative edge weights.

## Solution Approach
### Graph Representation
The road network is represented as a directed weighted graph where:
- *Nodes* represent intersections or key points.
- *Edges* represent roads between intersections with weights as travel time or cost.

### Steps
1. *Input the Graph*: Define the number of intersections and roads with weights (costs).
2. *Initialize Distances*: Set the source node distance to 0 and all others to infinity.
3. *Priority Queue*: Use a min-heap to extract the node with the smallest distance.
4. *Relaxation*: Update distances of adjacent nodes if a shorter path is found.
5. *Output*: Display the shortest path from the source to all nodes or report unreachable nodes.

## Implementation in C++
Below is the Dijkstra's algorithm implementation for road network design:


```cpp #include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int vertices, vector<vector<pii>>& graph, int source) {
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) continue;

        for (auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (distance[node] + weight < distance[nextNode]) {
                distance[nextNode] = distance[node] + weight;
                pq.push({distance[nextNode], nextNode});
            }
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

    vector<vector<pii>> graph(vertices);
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight}); // For undirected graph
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(vertices, graph, source);
    return 0;
} 
```

## Example Input/Output
### Input

Enter number of vertices and edges: 6 9
Enter edges (source destination weight):
0 1 4
0 2 4
1 2 2
1 3 5
2 3 8
2 4 10
3 4 2
3 5 6
4 5 3
Enter the source vertex: 0


### Output

Vertex\tDistance from Source
0\t0
1\t4
2\t4
3\t9
4\t11
5\t14


## Features
- *Dynamic Adjustments*: Efficiently handles changes in road conditions by recalculating shortest paths.
- *Scalable*: Works well for large networks with numerous intersections and roads.
- *Efficient*: Uses a priority queue for fast updates.


   

## Use Cases
- Urban road network optimization.
- Minimizing travel time for commuters.
- Emergency response route planning.

## Limitations
- Does not handle negative weight edges.
- Inefficient for dense graphs compared to other algorithms like Floyd-Warshall for all-pairs shortest paths.

## Future Enhancements
- Integrate real-time traffic data.
- Visualize the road network and routes.
- Support multi-objective optimization (e.g., time and fuel cost).

---




# Smart Public Transportation Scheduling

This project demonstrates an approach to solve *Smart Public Transportation Scheduling* using the Bellman-Ford algorithm in C++. The algorithm ensures optimized pathfinding, cost minimization, and better scheduling in a public transportation network.

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
- *Nodes* represent stops or stations.
- *Edges* represent routes between stops with weights as time or cost.

### Steps
1. *Input the Graph*: Define the number of stops and routes with weights (costs).
2. *Initialize Distances*: Set the source node distance to 0 and all others to infinity.
3. *Relaxation*: Iteratively update distances of all edges for V-1 times (where V is the number of nodes).
4. *Negative Cycle Detection*: Check for further relaxation; if possible, a negative cycle exists.
5. *Output*: Display the shortest path from the source to all stops or report unreachable stops.

## Implementation in C++
Below is the Bellman-Ford implementation for scheduling:

cpp
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


## Example Input/Output
### Input

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


### Output

Vertex\tDistance from Source
0\t0
1\t6
2\t7
3\t4
4\t2


## Features
- *Dynamic Updates*: Handle changing routes by re-running the algorithm.
- *Negative Weight Handling*: Accounts for delays or penalties in scheduling.
- *Scalability*: Works for large transportation networks with numerous stops and routes.



## Use Cases
- Public transport scheduling to reduce travel time.
- Urban planning for efficient mobility.
- Dynamic route adjustments during disruptions.

## Limitations
- Inefficient for dense graphs due to O(V * E) complexity.
- Does not handle undirected graphs with negative cycles.

## Future Enhancements
- Implement priority-based route selection.
- Integrate real-time data updates using APIs.
- Visualize the transportation network and paths.

---
### Water and Waste Management Optimization
- To solve the Water and Waste Management Optimization problem using the Floyd-Warshall algorithm, we can model it as a graph problem where:

- Nodes represent various locations (such as water treatment plants, waste disposal units, or city zones).
- Edges represent the transportation routes or connections between these locations (such as water pipelines, roads for waste collection, or infrastructure links).
- Edge weights represent the cost or time associated with transporting water or waste between two locations.
- The Floyd-Warshall algorithm can be used to compute the shortest path between all pairs of nodes in the graph. This will help optimize the routes for water distribution or -waste management by minimizing costs, time, or other resources. It can also be used for detecting the most efficient network structure for a city or area.

## Problem Breakdown
## Graph Representation:

- Nodes: Locations involved in the water and waste management system (e.g., water supply sources, treatment plants, disposal points).
- Edges: Pipelines, roads, or other routes connecting the nodes, with weights representing time, distance, or cost.
- Optimization Objective:

- Minimize transportation costs for water delivery and waste collection.
- Ensure all locations are connected optimally.
- Find the most efficient paths between any two points in the network.
### Approach using Floyd-Warshall
- Graph Initialization: Represent the system as a matrix where each element dist[i][j] contains the cost (or time) of travel between node i and node j. If no direct -- -connection exists, this value is set to a high value (representing infinity).

- Apply Floyd-Warshall: Use the algorithm to compute the shortest path between all pairs of nodes.

- Result: The resulting distance matrix will provide the optimized routes and costs for both water and waste management across the system.
cpp
#include <iostream>
#include <vector>
#define INF 99999999  // A large number representing infinity

using namespace std;

void floydWarshall(vector<vector<int>>& graph, int V) {
    // distance matrix to store the shortest path
    vector<vector<int>> dist = graph;

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V = 4; // Number of vertices
    // Initialize the graph with INF for no direct edge and 0 for diagonal elements
    vector<vector<int>> graph = {
        {0, 3, INF, INF},
        {2, 0, INF, INF},
        {INF, 7, 0, 1},
        {6, INF, INF, 0}
    };

    floydWarshall(graph, V);

    return 0;
}


- Enter number of vertices (locations) and edges (routes): 4 5
- Enter the edges (source destination cost):
- 0 1 5
- 0 2 10
- 1 2 3
- 1 3 1
- 2 3 2
## Shortest distances between every pair of vertices:
- 0 5 8 6 
- 999 0 3 1 
- 999 999 0 2 
- 999 999 999 0


## Example Problem: Water Distribution and Waste Collection Network
- Node  s: Locations involved in the system (water sources, treatment plants, collection points, etc.).
- Edges: Routes for transporting water or waste (pipelines, roads, etc.).
