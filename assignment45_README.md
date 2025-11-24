
# Assignment 45 - Graph Representation and Traversals Using Adjacency List

## Accepting Graph Input, Representing Using Adjacency List, and Performing BFS & DFS

This program accepts a graph input from the user, represents it using an adjacency list, and performs both Breadth-First Search (BFS) and Depth-First Search (DFS) traversals starting from a given source vertex.

### Operations Implemented
- **Graph Input:** The user inputs the number of vertices and edges, then provides each edge connecting two vertices.  
- **Adjacency List Representation:** The graph is stored as an array of vectors/lists where each index corresponds to a vertex and stores a list of adjacent vertices.  
- **Breadth-First Search (BFS):** Uses a queue to explore all neighbors at the current depth before moving to the next level, visiting vertices in layers.  
- **Depth-First Search (DFS):** Uses recursion or an explicit stack to explore as deeply as possible along each branch before backtracking.

### Key Concepts: Adjacency List and Graph Traversal

- **Adjacency List:** Space-efficient representation for sparse graphs and supports quick enumeration of a vertex’s neighbors.  
- **BFS:** Useful for shortest path in unweighted graphs, exploring vertices level by level.  
- **DFS:** Useful for pathfinding, connectivity, and cycle detection by exploring along branches.

### Time Complexity
- The adjacency list construction takes $$O(V + E)$$, where $$V$$ is number of vertices and $$E$$ number of edges.  
- BFS and DFS traversals have $$O(V + E)$$ complexity as each vertex and edge is processed once.

### Example

Input:
- Number of vertices: 4  
- Number of edges: 4  
- Edges: (0-1), (0-2), (1-2), (2-3)  
- Starting vertex for traversal: 0

Adjacency list representation:
- 0: 1, 2  
- 1: 0, 2  
- 2: 0, 1, 3  
- 3: 2  

BFS Traversal starting at 0: 0 1 2 3  
DFS Traversal starting at 0: 0 1 2 3

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Graph {
    int V;
    Node** adj;
public:
    Graph(int n) {
        V = n;
        adj = new Node*[V];
        for (int i = 0; i < V; i++) adj[i] = NULL;
    }

    void addEdge(int u, int v) {
        Node* temp = new Node{v, adj[u]};
        adj[u] = temp;

        temp = new Node{u, adj[v]};
        adj[v] = temp;
    }

    void BFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) visited[i] = false;

        int* q = new int[V];
        int front = 0, rear = 0;

        visited[start] = true;
        q[rear++] = start;

        while (front < rear) {
            int u = q[front++];
            cout << u << " ";
            Node* temp = adj[u];
            while (temp != NULL) {
                if (!visited[temp->data]) {
                    visited[temp->data] = true;
                    q[rear++] = temp->data;
                }
                temp = temp->next;
            }
        }
    }

    void DFSUtil(int u, bool visited[]) {
        visited[u] = true;
        cout << u << " ";
        Node* temp = adj[u];
        while (temp != NULL) {
            if (!visited[temp->data]) DFSUtil(temp->data, visited);
            temp = temp->next;
        }
    }

    void DFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) visited[i] = false;
        DFSUtil(start, visited);
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cin >> start;

    cout << "BFS: ";
    g.BFS(start);
    cout << "\nDFS: ";
    g.DFS(start);
}

```

### Applications
- Network routing, social network analysis, and connectivity checks.  
- Exploring possible paths and cycles in computational problems.  
- Base for algorithms in AI, puzzle solving, and graph algorithms.

***

