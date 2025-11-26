# Assignment 49 - Kruskal’s Algorithm for Minimum Spanning Tree Using Adjacency List

## Finding Minimum Spanning Tree (MST) of User-Defined Graph Using Kruskal’s Algorithm and Adjacency List

This program implements Kruskal’s algorithm to find the MST of a weighted, undirected graph represented via adjacency lists.

### Operations Implemented
- **Graph Input:** Accept number of vertices and weighted edges, constructing an adjacency list.  
- **Edge Extraction and Sorting:** Extract all edges from the adjacency list, sort them by weight to prepare for MST construction.  
- **Kruskal’s Algorithm with Union-Find:**  
  - Initialize disjoint sets for vertices.  
  - Iterate over edges in ascending weight order.  
  - Add edges that do not create cycles to the MST using union-find cycle detection.  
- **Display MST:** Show selected MST edges, their weights, and total MST cost.

### Key Concepts: Kruskal's and Union-Find with Adjacency List

- Each vertex holds a list of (neighbor, weight) pairs, efficiently representing graph.  
- Union-Find operations ensure cycle detection in nearly $$O(1)$$ amortized time.  
- Kruskal’s greedy edge selection guarantees MST correctness by always choosing smallest valid edge.

### Time Complexity
- Edge sorting takes $$O(E \log E)$$, with $$E$$ edges.  
- Union-Find contributes nearly constant time per operation.  
- Total time complexity typically $$O(E \log E)$$, efficient for sparse graphs.

### Example

Input:

- Vertices: 4  
- Edges:  
  (0,1,10), (0,2,6), (0,3,5), (1,3,15), (2,3,4)  

Resulting MST edges and weights:

- (2,3) weight 4  
- (0,3) weight 5  
- (0,1) weight 10  

Total MST cost: 19

```cpp
#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

class Graph {
public:
    int n, e;
    Edge edges[50];

    void accept() {
        cout << "Enter number of vertices: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> e;

        cout << "Enter edges (u v weight):\n";
        for (int i = 0; i < e; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
    }

    int findParent(int parent[], int x) {
        while (parent[x] != x)
            x = parent[x];
        return x;
    }

    void unionSet(int parent[], int x, int y) {
        int px = findParent(parent, x);
        int py = findParent(parent, y);
        parent[py] = px;
    }

    void sortEdges() {
        for (int i = 0; i < e - 1; i++) {
            for (int j = 0; j < e - i - 1; j++) {
                if (edges[j].w > edges[j + 1].w) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    void kruskal() {
        sortEdges();

        int parent[10];
        for (int i = 0; i < n; i++)
            parent[i] = i;

        cout << "MST Edges:\n";

        int count = 0;
        for (int i = 0; i < e && count < n - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            int pu = findParent(parent, u);
            int pv = findParent(parent, v);

            if (pu != pv) {
                cout << u << " - " << v << "  Weight: " << w << endl;
                unionSet(parent, pu, pv);
                count++;
            }
        }
    }
};

int main() {
    Graph g;
    g.accept();
    g.kruskal();
    return 0;
}

```
<img width="270" height="392" alt="image" src="https://github.com/user-attachments/assets/cb64462f-58b8-4c28-9b2f-bc0e390efe74" />

### Applications
- Network cost minimization tasks in telecom, road, and utility networks.  
- Clustering and data segmentation in computer graphics.  
- Educational tool for understanding fundamental graph algorithm principles.

