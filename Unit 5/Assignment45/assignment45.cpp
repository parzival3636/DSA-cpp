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
