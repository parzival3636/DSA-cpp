#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int v, w;
};

class Graph {
public:
    int n, e;
    Edge adj[10][10];
    int adjSize[10];

    void accept() {
        cout << "Enter number of vertices: ";
        cin >> n;

        for (int i = 0; i < n; i++)
            adjSize[i] = 0;

        cout << "Enter number of edges: ";
        cin >> e;

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

    int minVertex(int dist[], bool visited[]) {
        int minVal = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minVal) {
                minVal = dist[i];
                idx = i;
            }
        }
        return idx;
    }

    void dijkstra(int start) {
        int dist[10];
        bool visited[10];

        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[start] = 0;

        for (int k = 0; k < n - 1; k++) {
            int u = minVertex(dist, visited);
            visited[u] = true;

            for (int i = 0; i < adjSize[u]; i++) {
                int v = adj[u][i].v;
                int w = adj[u][i].w;

                if (!visited[v] && dist[u] != INT_MAX &&
                    dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < n; i++) {
            cout << start << " -> " << i << " = " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g;
    g.accept();

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    g.dijkstra(start);
    return 0;
}
