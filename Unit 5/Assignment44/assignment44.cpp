#include <iostream>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
    int v, w;
    Edge* next;
};

int main() {
    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge* adj[50];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    cout << "\nEnter edges in format (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        Edge* a = new Edge{v, w, adj[u]};
        adj[u] = a;

        Edge* b = new Edge{u, w, adj[v]};
        adj[v] = b;   // because graph is undirected
    }

    int src;
    cout << "\nEnter source vertex: ";
    cin >> src;

    int dist[50], visited[50];
    for (int i = 0; i < n; i++) {
        dist[i] = numeric_limits<int>::max();
        visited[i] = 0;
    }

    priority_queue<pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        for (Edge* ptr = adj[u]; ptr != NULL; ptr = ptr->next) {
            int v = ptr->v;
            int w = ptr->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " → Distance = ";
        if (dist[i] == numeric_limits<int>::max())
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}
