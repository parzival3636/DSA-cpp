#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int v;
    int w;
};

class Graph {
public:
    int n, e;
    Edge adj[10][10];
    int adjSize[10];

    void accept() {
        cout << "Enter number of vertices: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> e;

        for (int i = 0; i < n; i++)
            adjSize[i] = 0;

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

    int findMin(int key[], bool mst[]) {
        int minVal = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++) {
            if (!mst[i] && key[i] < minVal) {
                minVal = key[i];
                idx = i;
            }
        }
        return idx;
    }

    void prim() {
        int parent[10];
        int key[10];
        bool mst[10];

        for (int i = 0; i < n; i++) {
            key[i] = INT_MAX;
            mst[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < n - 1; count++) {
            int u = findMin(key, mst);
            mst[u] = true;

            for (int i = 0; i < adjSize[u]; i++) {
                int v = adj[u][i].v;
                int w = adj[u][i].w;

                if (!mst[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        cout << "MST Edges:\n";
        for (int i = 1; i < n; i++)
            cout << parent[i] << " - " << i << "  Weight: " << key[i] << endl;
    }
};

int main() {
    Graph g;
    g.accept();
    g.prim();
    return 0;
}
