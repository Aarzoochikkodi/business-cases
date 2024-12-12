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
