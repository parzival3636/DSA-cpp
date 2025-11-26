
# Assignment 42 - Prim’s Algorithm for Minimum Spanning Tree Using Adjacency List

## Finding Minimum Spanning Tree (MST) Using Prim’s Algorithm with Adjacency List Representation

This program implements Prim’s algorithm to find the MST of a user-defined weighted, undirected graph. The graph is represented using an adjacency list for efficient storage, especially useful for sparse graphs.

### Operations Implemented
- **Graph Input:** Accept number of vertices and weighted edges, then build adjacency lists reflecting connected vertices and edge weights.  
- **Prim’s Algorithm:**  
  - Start from an arbitrary vertex.  
  - Repeatedly add the smallest-weight edge connecting the included MST vertex set to an excluded vertex, until all vertices are included.  
- **Display MST:** Output the edges selected in the MST with their weights and the total minimum cost.

### Key Concepts: Prim’s Algorithm and Adjacency List

- **Adjacency List:** Each vertex stores a list of pairs (neighbor vertex and edge weight), making it efficient for sparse graphs.  
- **Prim’s Algorithm:** Uses a priority queue to greedily select lowest-weight edges while avoiding cycles, ensuring minimum spanning tree.

### Time Complexity
- Using adjacency list with a priority queue (min-heap), time complexity is $$O(E \log V)$$, where $$E$$ is edges and $$V$$ is vertices.

### Example

User inputs:

- Vertices: 4  
- Edges:  
  (0, 1, 10), (0, 2, 6), (0, 3, 5), (1, 3, 15), (2, 3, 4)  

MST Edges:

- (2, 3) weight 4  
- (0, 3) weight 5  
- (0, 1) weight 10  

Total MST Weight: 19

### Applications
- Network design (telecom, computer networks) minimizing wiring costs.  
- Clustering algorithms in data mining.  
- Designing efficient road or utility layouts.



```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n, 1e9), parent(n, -1), inMST(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = 1;

        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " : " << key[i] << endl;

    return 0;
}

```

<img width="217" height="221" alt="image" src="https://github.com/user-attachments/assets/7c1970bc-e909-4695-86d4-592c1019de06" />

<img width="177" height="139" alt="image" src="https://github.com/user-attachments/assets/d7709974-f017-4550-a374-b415d0812abe" />

