#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent, parent[x]);
}

void unite(int parent[], int rank[], int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[b] < rank[a]) parent[b] = a;
    else { parent[b] = a; rank[a]++; }
}

int main() {
    int n;
    cin >> n;
    int adj[20][20];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    Edge edges[400];
    int k = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (adj[i][j] != 0) {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].w = adj[i][j];
                k++;
            }

    for (int i = 0; i < k - 1; i++)
        for (int j = 0; j < k - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    int parent[20], rank[20];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int total = 0;
    cout << "MST:\n";

    for (int i = 0; i < k; i++) {
        int a = findParent(parent, edges[i].u);
        int b = findParent(parent, edges[i].v);
        if (a != b) {
            unite(parent, rank, a, b);
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << "\n";
            total += edges[i].w;
        }
    }

    cout << "Total Weight = " << total;
}
