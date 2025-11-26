
# Assignment 50 - Dijkstra’s Algorithm for Shortest Distance Using Adjacency List

## Finding Shortest Distance Between Two Nodes in a User-Defined Graph Using Dijkstra’s Algorithm

This program implements Dijkstra’s algorithm to find the shortest path between two nodes in a weighted graph represented by an adjacency list.

### Operations Implemented
- **Graph Input:** The user specifies the number of vertices and edges, and inputs each edge with its cost. The graph is stored as an adjacency list where each vertex stores pairs of adjacent vertex and edge cost.  
- **Dijkstra’s Algorithm:**  
  - Initialize distances to all nodes as infinity except the start node set to zero.  
  - Use a priority queue (min-heap) to repeatedly extract the vertex with the smallest current distance.  
  - For each neighbor of the extracted vertex, relax the edge if a shorter path is found by updating the neighbor’s distance.  
- **Output:** Display the shortest distance between the given source and destination nodes and optionally the path.

### Key Concepts: Adjacency List and Priority Queue in Dijkstra’s Algorithm

- **Adjacency List:** Efficient representation of graphs, especially sparse, allowing quick adjacency access.  
- **Priority Queue:** Ensures selection of the next vertex with the minimum tentative distance efficiently.  
- **Relaxation:** The process of checking and updating distances yields optimal shortest paths.

### Time Complexity
- The algorithm runs in $$O(E \log V)$$ time where $$V$$ is vertices and $$E$$ is edges due to priority queue operations.

### Example

Input:
- Vertices: 5  
- Edges:  
  (0, 1, 2), (0, 2, 4), (1, 2, 1), (1, 3, 7), (2, 4, 3), (3, 4, 1)  
- Source vertex: 0  
- Destination vertex: 4

Output:  
Shortest distance from 0 to 4 = 6  
Shortest path: 0 -> 1 -> 2 -> 4

```cpp
#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int v, w;
};

class Graph {
public:
    int n, e;
    Edge adj[10][10];
    int adjSize[10];

    void accept() {
        cout << "Enter number of vertices: ";
        cin >> n;

        for (int i = 0; i < n; i++)
            adjSize[i] = 0;

        cout << "Enter number of edges: ";
        cin >> e;

        cout << "Enter edges (u v weight):\n";
        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u][ adjSize[u] ].v = v;
            adj[u][ adjSize[u] ].w = w;
            adjSize[u]++;

            adj[v][ adjSize[v] ].v = u;
            adj[v][ adjSize[v] ].w = w;
            adjSize[v]++;
        }
    }

    int minVertex(int dist[], bool visited[]) {
        int minVal = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minVal) {
                minVal = dist[i];
                idx = i;
            }
        }
        return idx;
    }

    void dijkstra(int start) {
        int dist[10];
        bool visited[10];

        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[start] = 0;

        for (int k = 0; k < n - 1; k++) {
            int u = minVertex(dist, visited);
            visited[u] = true;

            for (int i = 0; i < adjSize[u]; i++) {
                int v = adj[u][i].v;
                int w = adj[u][i].w;

                if (!visited[v] && dist[u] != INT_MAX &&
                    dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < n; i++) {
            cout << start << " -> " << i << " = " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g;
    g.accept();

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    g.dijkstra(start);
    return 0;
}

```
<img width="276" height="424" alt="image" src="https://github.com/user-attachments/assets/e6ffe132-6c29-4eef-8369-576145e6a7fa" />

### Applications
- Network routing and traffic navigation systems.  
- Resource optimization and scheduling.  
- Widely used foundation for many graph and pathfinding problems.

***

