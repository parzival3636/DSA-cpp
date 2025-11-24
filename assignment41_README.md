# Assignment 41- Graph Representation and Traversals (BFS & DFS) Using Adjacency Matrix

## Accepting Graph Input, Representing Using Adjacency Matrix, and Performing BFS & DFS

This program accepts a user-input graph (number of vertices and edges), represents it as an adjacency matrix, and performs both Breadth-First Search (BFS) and Depth-First Search (DFS) traversals starting from a given source vertex.

### Operations Implemented
- **Graph Input:** Accept number of vertices and edges, then read edges to build the adjacency matrix.  
- **Adjacency Matrix Representation:** Use a 2D array where `matrix[i][j] = 1` indicates an edge from vertex `i` to vertex `j`.  
- **Breadth-First Search (BFS):** Traverse vertices level-wise using a queue, visiting neighbors iteratively.  
- **Depth-First Search (DFS):** Traverse deeply along edges using recursion or an explicit stack, visiting adjacent unvisited vertices.

### Key Concepts: Adjacency Matrix and Graph Traversal

- **Adjacency Matrix:** Simple, fixed-size graph representation suitable for dense graphs or when quick edge checks are needed.  
- **BFS:** Good for shortest path in unweighted graphs and layer-by-layer exploration.  
- **DFS:** Useful for connectivity, cycles, and topological ordering.

### Time Complexity
- Creating adjacency matrix: $$O(V^2)$$, where $$V$$ is the number of vertices.  
- BFS and DFS both run in $$O(V^2)$$ with adjacency matrix due to checking all vertex pairs.

### Example

Input:
- Number of vertices: 4  
- Number of edges: 4  
- Edges: (0-1), (0-2), (1-2), (2-3)  
- Starting vertex for traversal: 0

Adjacency matrix:

|   | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 | 0 |
| 2 | 0 | 0 | 0 | 1 |
| 3 | 0 | 0 | 0 | 0 |

BFS Traversal starting at 0: 0 1 2 3  
DFS Traversal starting at 0: 0 1 2 3


```cpp
#include <iostream>
#include <queue>
using namespace std;

void bfs_rrl(int vertices_rrl, int adjMatrix_rrl[][10], int start_rrl) {
    bool visited_rrl[vertices_rrl];
    for (int i_rrl = 0; i_rrl < vertices_rrl; i_rrl++)
        visited_rrl[i_rrl] = false;

    queue<int> q_rrl;
    q_rrl.push(start_rrl);
    visited_rrl[start_rrl] = true;

    cout << "BFS Traversal: ";
    while (!q_rrl.empty()) {
        int current_rrl = q_rrl.front();
        q_rrl.pop();
        cout << current_rrl << " ";
        for (int i_rrl = 0; i_rrl < vertices_rrl; i_rrl++) {
            if (adjMatrix_rrl[current_rrl][i_rrl] && !visited_rrl[i_rrl]) {
                q_rrl.push(i_rrl);
                visited_rrl[i_rrl] = true;
            }
        }
    }
    cout << endl;
}

void dfs_rrl(int vertices_rrl, int adjMatrix_rrl[][10], int start_rrl) {
    bool visited_rrl[vertices_rrl];
    for (int i_rrl = 0; i_rrl < vertices_rrl; i_rrl++)
        visited_rrl[i_rrl] = false;

    int stack_rrl[vertices_rrl];
    int top_rrl = -1;
    stack_rrl[++top_rrl] = start_rrl;

    cout << "DFS Traversal: ";
    while (top_rrl >= 0) {
        int current_rrl = stack_rrl[top_rrl--];
        if (!visited_rrl[current_rrl]) {
            cout << current_rrl << " ";
            visited_rrl[current_rrl] = true;
            for (int i_rrl = vertices_rrl - 1; i_rrl >= 0; i_rrl--) {
                if (adjMatrix_rrl[current_rrl][i_rrl] && !visited_rrl[i_rrl]) {
                    stack_rrl[++top_rrl] = i_rrl;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices_rrl, choice_rrl, start_rrl;
    int adjMatrix_rrl[10][10];

    cout << "Enter number of vertices: ";
    cin >> vertices_rrl;

    cout << "Enter adjacency matrix:\n";
    for (int i_rrl = 0; i_rrl < vertices_rrl; i_rrl++) {
        for (int j_rrl = 0; j_rrl < vertices_rrl; j_rrl++) {
            cin >> adjMatrix_rrl[i_rrl][j_rrl];
        }
    }

    while (true) {
        cout << "\n1. BFS Traversal\n2. DFS Traversal\n3. Exit\nEnter choice: ";
        cin >> choice_rrl;

        if (choice_rrl == 1) {
            cout << "Enter starting vertex (0-" << vertices_rrl - 1 << "): ";
            cin >> start_rrl;
            bfs_rrl(vertices_rrl, adjMatrix_rrl, start_rrl);
        }
        else if (choice_rrl == 2) {
            cout << "Enter starting vertex (0-" << vertices_rrl - 1 << "): ";
            cin >> start_rrl;
            dfs_rrl(vertices_rrl, adjMatrix_rrl, start_rrl);
        }
        else if (choice_rrl == 3) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
```


### Output:
<img width="345" height="725" alt="image" src="https://github.com/user-attachments/assets/d038aaf7-8286-4953-8383-9016d18c717b" />
<img width="684" height="472" alt="image" src="https://github.com/user-attachments/assets/3ca870da-23b0-4c27-aad0-3f95ff2fb208" />


### Applications
- Network routing, social network analysis.  
- Solving puzzles and games modeled as graphs.  
- Analyzing connectivity and reachability in various domains.

