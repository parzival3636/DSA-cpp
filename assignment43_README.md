# Assignment 43 - Kruskal’s Algorithm for Minimum Spanning Tree Using Adjacency List

## Finding Minimum Spanning Tree (MST) with Kruskal’s Algorithm on User-Defined Graph

This program implements Kruskal’s algorithm to find the MST of a weighted, undirected graph. The graph is represented using an adjacency list, and the algorithm uses a disjoint set (union-find) data structure for cycle detection.

### Operations Implemented
- **Graph Input:** Accept number of vertices and edges, build adjacency list of each vertex along with edge weights.  
- **Edge Sorting:** Extract all edges and sort by increasing weight.  
- **Kruskal’s Algorithm:**  
  - Iterate edges in ascending order of weight.  
  - Add edge to MST if it does not create a cycle (using union-find to test).  
- **Display MST:** List edges included in the MST with their weights and total MST cost.

### Key Concepts: Kruskal’s Algorithm and Disjoint Sets

- **Adjacency List:** Efficient representation especially for sparse graphs.  
- **Disjoint Set (Union-Find):** Supports quick cycle detection by tracking connected components and merging them safely.  
- **Kruskal’s Algorithm:** Greedy choice of minimum edges first, building MST component-by-component with cycle checks.

### Time Complexity
- Edge sorting: $$O(E \log E)$$.  
- Union-find operations: nearly $$O(1)$$ amortized per union/find.  
- Total: $$O(E \log E)$$, suitable for graphs where $$E$$ is number of edges.

### Example

User inputs:

- Vertices: 4  
- Edges:   
  (0, 1, 10), (0, 2, 6), (0, 3, 5), (1, 3, 15), (2, 3, 4)  

MST edges:

- (2, 3) weight 4  
- (0, 3) weight 5  
- (0, 1) weight 10  

Total MST Weight: 19


```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int v, vector<int> &parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[b] < rank[a]) parent[b] = a;
    else { parent[b] = a; rank[a]++; }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    vector<Edge> mst;

    for (auto &edge : edges) {
        int pu = findParent(edge.u, parent);
        int pv = findParent(edge.v, parent);
        if (pu != pv) {
            mst.push_back(edge);
            unionSet(pu, pv, parent, rank);
        }
    }

    for (auto &e : mst)
        cout << e.u << " - " << e.v << " : " << e.w << endl;

    return 0;
}

```

### Applications
- Network design for minimizing overall costs.  
- Clustering and partitioning in data science and computer graphics.  
- Road and utility planning.

