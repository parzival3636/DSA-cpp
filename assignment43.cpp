#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int v, vector<int> &parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[b] < rank[a]) parent[b] = a;
    else { parent[b] = a; rank[a]++; }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    vector<Edge> mst;

    for (auto &edge : edges) {
        int pu = findParent(edge.u, parent);
        int pv = findParent(edge.v, parent);
        if (pu != pv) {
            mst.push_back(edge);
            unionSet(pu, pv, parent, rank);
        }
    }

    for (auto &e : mst)
        cout << e.u << " - " << e.v << " : " << e.w << endl;

    return 0;
}
