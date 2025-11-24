#include <iostream>
#include <queue>
using namespace std;

struct Edge {
    int v, w;
    Edge* next;
};

int main() {
    int n, e;
    cin >> n >> e;

    Edge* adj[50];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge* a = new Edge{v, w, adj[u]};
        adj[u] = a;
        Edge* b = new Edge{u, w, adj[v]};
        adj[v] = b;
    }

    int src;
    cin >> src;

    int dist[50], visited[50];
    for (int i = 0; i < n; i++) {
        dist[i] = 1e9;
        visited[i] = 0;
    }

    priority_queue<pair<int,int>, 
        queue<pair<int,int>>, 
        greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = 1;

        Edge* ptr = adj[u];
        while (ptr) {
            int v = ptr->v;
            int w = ptr->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
            ptr = ptr->next;
        }
    }

    for (int i = 0; i < n; i++)
        cout << i << " : " << dist[i] << endl;

    return 0;
}
