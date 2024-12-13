#include <iostream>
#include <vector>
// #include <limits>

using namespace std;

class graph {
    int v;
    vector<vector<int>> edges;

public:
    graph(int vertices) {
        v = vertices;
    }

    void add_edge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    void print_arr(vector<int>& dist) {
        cout << "vertex distance from source\n";
        for (int i = 0; i < v; i++) {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }

    void bellman_ford(int src) {
        vector<int> dist(v, 9999);
        dist[src] = 0;

        for (int i = 0; i < v - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] != 9999 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != 9999 && dist[u] + w < dist[v]) {
                cout << "graph contains negative weight cycle\n";
                return;
            }
        }

        print_arr(dist);
    }
};

int main() {
    graph g(5);

    g.add_edge(0, 1, 12);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 3, 9);
    g.add_edge(1, 4, 14);
    g.add_edge(3, 2, 51);
    g.add_edge(3, 1, 2);
    g.add_edge(4, 3, -2);

    g.bellman_ford(0);

    return 0;
}
