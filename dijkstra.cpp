#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class graph {
    vector<vector<int>> adjacent;
    vector<string> vertex_data;
    int size;

public:
    graph(int size) {
        this->size = size;
        adjacent.resize(size, vector<int>(size, 0));
        vertex_data.resize(size, "");
    }

    void add_edge(int u, int v, int weight) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            adjacent[u][v] = weight;
            adjacent[v][u] = weight;
        }
    }

    void add_vertex_data(int vertex, string data) {
        if (vertex >= 0 && vertex < size) {
            vertex_data[vertex] = data;
        }
    }

    vector<int> dijkstra(string start_vertex_data) {
        int start_vertex = -1;
        for (int i = 0; i < size; i++) {
            if (vertex_data[i] == start_vertex_data) {
                start_vertex = i;
                break;
            }
        }

        vector<int> distances(size, numeric_limits<int>::max());
        distances[start_vertex] = 0;
        vector<bool> visited(size, false);

        for (int count = 0; count < size; count++) {
            int min_distance = numeric_limits<int>::max();
            int u = -1;

            for (int i = 0; i < size; i++) {
                if (!visited[i] && distances[i] < min_distance) {
                    min_distance = distances[i];
                    u = i;
                }
            }

            if (u == -1) {
                break;
            }

            visited[u] = true;

            for (int v = 0; v < size; v++) {
                if (adjacent[u][v] != 0 && !visited[v]) {
                    int alt = distances[u] + adjacent[u][v];
                    if (alt < distances[v]) {
                        distances[v] = alt;
                    }
                }
            }
        }

        return distances;
    }

    string get_vertex_data(int i) {
        return vertex_data[i];
    }
};

int main() {
    graph g(7);
    g.add_vertex_data(0, "A");
    g.add_vertex_data(1, "B");
    g.add_vertex_data(2, "C");
    g.add_vertex_data(3, "D");
    g.add_vertex_data(4, "E");
    g.add_vertex_data(5, "F");
    g.add_vertex_data(6, "G");

    g.add_edge(3, 0, 5);
    g.add_edge(3, 4, 12);
    g.add_edge(0, 2, 18);
    g.add_edge(4, 1, 4);
    g.add_edge(4, 2, 4);
    g.add_edge(0, 6, 5);
    g.add_edge(2, 5, 9);
    g.add_edge(1, 2, 12);
    g.add_edge(3, 5, 2);
    g.add_edge(6, 5, 5);
    cout << "Dijkstra's Algorithm starting from vertex D:\n";
    vector<int> distances = g.dijkstra("D");

    for (int i = 0; i < distances.size(); i++) {
        cout << "Shortest distance from D to " << g.get_vertex_data(i) << ": " << distances[i] << endl;
    }

    return 0;
}
