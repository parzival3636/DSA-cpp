
# Assignment 46 - Kruskal’s Algorithm for Minimum Spanning Tree Using Adjacency Matrix

## Finding Minimum Spanning Tree (MST) of a User-Defined Graph Using Kruskal’s Algorithm

This program implements Kruskal’s algorithm to find the MST of a weighted, undirected graph represented as an adjacency matrix.

### Operations Implemented
- **Graph Input:** Accept number of vertices and weighted edges, then build an adjacency matrix where `matrix[i][j]` stores weight of edge between vertices `i` and `j` (0 or infinity if no edge).  
- **Edge Extraction & Sorting:** Extract edges from the matrix and sort them by increasing weight.  
- **Kruskal’s Algorithm:**  
  - Initialize disjoint sets for each vertex.  
  - Iterate over sorted edges, and add an edge to MST if it does not form a cycle (detected using union-find).  
- **Display MST:** List edges in the MST along with their weights and the total minimum cost.

### Key Concepts: Kruskal’s Algorithm using Adjacency Matrix

- **Adjacency Matrix:** Straightforward graph representation, especially useful for dense graphs or small vertex sets.  
- **Disjoint Set (Union-Find):** Efficient cycle detection during MST construction.  
- **Kruskal’s Algorithm:** Greedy approach selecting edges with smallest weight ensuring MST properties.

### Time Complexity
- Edge sorting: $$O(E \log E)$$, with $$E = V^2$$ for dense graphs represented by adjacency matrix.  
- Union-find operations: near $$O(1)$$ amortized per edge.  
- Total: approximately $$O(V^2 \log V)$$ for dense graphs.

### Example

User inputs:

- Vertices: 4  
- Adjacency matrix (0 for no edge):

|   | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| 0 | 0 | 10| 6 | 5 |
| 1 | 10| 0 | 0 | 15|
| 2 | 6 | 0 | 0 | 4 |
| 3 | 5 | 15| 4 | 0 |

MST Edges:

- (2, 3) weight 4  
- (0, 3) weight 5  
- (0, 1) weight 10  

Total MST Weight: 19

```cpp
#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent, parent[x]);
}

void unite(int parent[], int rank[], int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[b] < rank[a]) parent[b] = a;
    else { parent[b] = a; rank[a]++; }
}

int main() {
    int n;
    cin >> n;
    int adj[20][20];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    Edge edges[400];
    int k = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (adj[i][j] != 0) {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].w = adj[i][j];
                k++;
            }

    for (int i = 0; i < k - 1; i++)
        for (int j = 0; j < k - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    int parent[20], rank[20];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int total = 0;
    cout << "MST:\n";

    for (int i = 0; i < k; i++) {
        int a = findParent(parent, edges[i].u);
        int b = findParent(parent, edges[i].v);
        if (a != b) {
            unite(parent, rank, a, b);
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << "\n";
            total += edges[i].w;
        }
    }

    cout << "Total Weight = " << total;
}

```

### Applications
- Network design and optimization tasks.  
- Planning efficient transportation and utility layouts.  
- Teaching foundational graph algorithms and MST concepts.

***

