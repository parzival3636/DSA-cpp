# Assignment 44 - Dijkstra’s Algorithm for Shortest Path Using Adjacency List

## Finding Shortest Distance Between Two Nodes in User-Defined Graph Using Dijkstra’s Algorithm

This program implements Dijkstra’s algorithm to find the shortest distance between two vertices in a weighted graph. The graph is represented using an adjacency list for efficient storage, especially for sparse graphs.

### Operations Implemented
- **Graph Input:** Accept number of vertices and edges, build adjacency list storing neighboring vertices and edge weights.  
- **Dijkstra’s Algorithm:**  
  - Initialize distances with infinity, distance to source vertex as zero.  
  - Use a priority queue (min-heap) to greedily select the vertex with the smallest tentative distance.  
  - Relax neighbors updating shortest paths until the shortest path to destination is found.  
- **Display Shortest Distance and Path:** Output the minimum distance and optionally print the shortest path.

### Key Concepts: Dijkstra’s Algorithm and Adjacency List

- **Adjacency List:** Provides efficient graph representation with quick access to neighbors.  
- **Priority Queue:** Optimizes selection of next vertex to process by shortest tentative distance.  
- **Relaxation:** Updates distances ensuring shortest paths are correctly computed.

### Time Complexity
- Using adjacency list with a min-priority queue, time complexity is approximately $$O(E \log V)$$ where $$E$$ is edges and $$V$$ is vertices.

### Example

Input:

- Vertices: 5  
- Edges:  
  (0, 1, 2), (0, 2, 4), (1, 2, 1), (1, 3, 7), (2, 4, 3), (3, 4, 1)  
- Source: 0, Destination: 4

Output:  
Shortest distance from 0 to 4 is 6  
Shortest path: 0 -> 1 -> 2 -> 4


```cpp
#include <iostream>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
    int v, w;
    Edge* next;
};

int main() {
    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge* adj[50];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    cout << "\nEnter edges in format (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        Edge* a = new Edge{v, w, adj[u]};
        adj[u] = a;

        Edge* b = new Edge{u, w, adj[v]};
        adj[v] = b;   // because graph is undirected
    }

    int src;
    cout << "\nEnter source vertex: ";
    cin >> src;

    int dist[50], visited[50];
    for (int i = 0; i < n; i++) {
        dist[i] = numeric_limits<int>::max();
        visited[i] = 0;
    }

    priority_queue<pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        for (Edge* ptr = adj[u]; ptr != NULL; ptr = ptr->next) {
            int v = ptr->v;
            int w = ptr->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " → Distance = ";
        if (dist[i] == numeric_limits<int>::max())
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}

```
<img width="300" height="471" alt="image" src="https://github.com/user-attachments/assets/4307a2a7-7f06-4882-b6b5-e74fe88b54c8" />


### Applications
- Network routing and navigation systems.  
- GPS and mapping software for shortest route calculations.  
- Resource planning and robotics.

