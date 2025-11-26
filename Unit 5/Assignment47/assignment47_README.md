# Assignment 47 - Dijkstra’s Algorithm for Shortest Distance Using Adjacency Matrix

## Finding Shortest Distance Between Two Nodes in User-defined Graph Listed as Adjacency Matrix

This program implements Dijkstra’s algorithm to find the shortest path between two given vertices in a weighted, directed/undirected graph represented by an adjacency matrix.

### Operations Implemented
- **Graph Input:** User inputs number of vertices and weighted adjacency matrix values, where `matrix[i][j]` holds weight of edge or 0/inf for no direct path.  
- **Dijkstra’s Algorithm:**  
  - Initialize distance array with infinity except for the source vertex set to zero.  
  - Use an array or set to track included vertices.  
  - Iteratively select the vertex with minimum tentative distance not yet processed.  
  - Relax edges from the selected vertex, updating distances if shorter paths found.  
- **Display Shortest Distance and Path:** Output the shortest distance and reconstruct the path from source to destination.

### Key Concepts: Dijkstra’s Algorithm with Adjacency Matrix

- **Adjacency Matrix:** Enables direct access to edge weights between any two vertices in constant time; suitable for graphs with many edges.  
- **Relaxation:** Ensures shortest distances are updated by continuously checking edges from the nearest vertex.  
- **Path Reconstruction:** Maintains a predecessor array to trace back the shortest path once computation finishes.

### Time Complexity
- Time complexity is $$O(V^2)$$ using adjacency matrix and simple arrays, with $$V$$ vertices.  
- More efficient approaches use adjacency lists and priority queues for sparse graphs.

### Example

User Input:

- Vertices: 5  
- Adjacency matrix (0 indicates no direct edge):

|   | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| 0 | 0 | 2 | 4 | 0 | 0 |
| 1 | 2 | 0 | 1 | 7 | 0 |
| 2 | 4 | 1 | 0 | 0 | 3 |
| 3 | 0 | 7 | 0 | 0 | 1 |
| 4 | 0 | 0 | 3 | 1 | 0 |

- Source: 0  
- Destination: 4  

Output:  
Shortest distance from 0 to 4 = 7  
Shortest path: 0 → 1 → 2 → 4

```cpp
#include <iostream>
#include <climits>
using namespace std;

class Graph {
public:
    int n;
    int adj[10][10];

    void accept() {
        cout << "Enter number of vertices: ";
        cin >> n;
        cout << "Enter adjacency matrix (0 for no edge):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adj[i][j];
            }
        }
    }

    int findMin(int dist[], bool visited[]) {
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

        for (int i = 0; i < n - 1; i++) {
            int u = findMin(dist, visited);
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && adj[u][v] != 0 && dist[u] != INT_MAX
                    && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < n; i++)
            cout << start << " -> " << i << " = " << dist[i] << endl;
    }
};

int main() {
    Graph g;
    int start;

    g.accept();
    cout << "Enter starting vertex: ";
    cin >> start;

    g.dijkstra(start);
    return 0;
}

```

<img width="323" height="515" alt="image" src="https://github.com/user-attachments/assets/fd714449-25e6-429c-af02-fcfc84190d30" />


### Applications
- Road and network navigation systems.  
- Optimal resource allocation and routing.  
- Widely used in communication and transportation algorithms.

***
