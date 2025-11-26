
# Assignment 48 - Prim’s Algorithm for Minimum Spanning Tree Using Adjacency List

## Finding Minimum Spanning Tree (MST) of User-Defined Graph Using Prim’s Algorithm and Adjacency List

This program guides creating a weighted, undirected graph represented as an adjacency list and implements Prim’s algorithm to find its MST efficiently.

### Operations Implemented
- **Graph Input:** Accept number of vertices and weighted edges to build adjacency lists, storing neighbors along with edge weights.  
- **Prim’s Algorithm:**  
  - Begin at arbitrary vertex; maintain a priority queue of edges crossing the cut between visited and unvisited vertices.  
  - Select minimum weight edge extending MST each iteration and add to MST if it connects new vertex.  
  - Continue until all vertices included.  
- **Display MST:** Output edges with their weights constituting the MST and total minimum spanning cost.

### Key Concepts: Prim’s Algorithm and Adjacency List

- **Adjacency List:** Stores compact graph representation suitable for sparse graphs, allowing quick access to a vertex’s neighbors.  
- **Priority Queue:** Facilitates selecting the minimum edge efficiently during MST growth.  
- **Cut Property:** Fundamental to MST correctness, selecting minimum crossing edge is guaranteed safe.

### Time Complexity

- Overall complexity is $$O(E \log V)$$ using adjacency list with a priority queue, where $$E$$ is number of edges and $$V$$ vertices.

### Example

User Input:

- Vertices: 4  
- Edges (with weights):  
  (0, 1, 10), (0, 2, 6), (0, 3, 5), (1, 3, 15), (2, 3, 4)  

Resulting MST edges:

- (2, 3) weight 4  
- (0, 3) weight 5  
- (0, 1) weight 10  

Total MST Weight: 19

```cpp
#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int v;
    int w;
};

class Graph {
public:
    int n, e;
    Edge adj[10][10];
    int adjSize[10];

    void accept() {
        cout << "Enter number of vertices: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> e;

        for (int i = 0; i < n; i++)
            adjSize[i] = 0;

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

    int findMin(int key[], bool mst[]) {
        int minVal = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++) {
            if (!mst[i] && key[i] < minVal) {
                minVal = key[i];
                idx = i;
            }
        }
        return idx;
    }

    void prim() {
        int parent[10];
        int key[10];
        bool mst[10];

        for (int i = 0; i < n; i++) {
            key[i] = INT_MAX;
            mst[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < n - 1; count++) {
            int u = findMin(key, mst);
            mst[u] = true;

            for (int i = 0; i < adjSize[u]; i++) {
                int v = adj[u][i].v;
                int w = adj[u][i].w;

                if (!mst[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        cout << "MST Edges:\n";
        for (int i = 1; i < n; i++)
            cout << parent[i] << " - " << i << "  Weight: " << key[i] << endl;
    }
};

int main() {
    Graph g;
    g.accept();
    g.prim();
    return 0;
}

```
<img width="392" height="391" alt="image" src="https://github.com/user-attachments/assets/2cdf8602-864c-4c6e-92a4-e9a7512e637b" />

### Applications  
- Design of cost-effective networks such as telecommunication or electrical grids.  
- Clustering in data analysis and computer graphics.  
- Efficient resource allocation in distributed systems.

***

