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
