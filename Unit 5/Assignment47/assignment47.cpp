#include <iostream>
#include <climits>
using namespace std;

class Graph {
public:
    int n;
    int adj[10][10];

    void accept() {
        cout << "Enter number of vertices: ";
        cin >> n;
        cout << "Enter adjacency matrix (0 for no edge):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adj[i][j];
            }
        }
    }

    int findMin(int dist[], bool visited[]) {
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

        for (int i = 0; i < n - 1; i++) {
            int u = findMin(dist, visited);
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && adj[u][v] != 0 && dist[u] != INT_MAX
                    && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < n; i++)
            cout << start << " -> " << i << " = " << dist[i] << endl;
    }
};

int main() {
    Graph g;
    int start;

    g.accept();
    cout << "Enter starting vertex: ";
    cin >> start;

    g.dijkstra(start);
    return 0;
}
