#include <bits/stdc++.h>
using namespace std;

void edgeAdd(vector<vector<int>> &adjacencyList, int source, int target) {
    adjacencyList[source].push_back(target);
    adjacencyList[target].push_back(source);
}

void dfs(const vector<vector<int>> &adjacencyList, vector<bool> &visited, int currentVertex) {
    visited[currentVertex] = true;
    cout << currentVertex << " ";

    for (int neighbor : adjacencyList[currentVertex]) {
        if (!visited[neighbor]) {
            dfs(adjacencyList, visited, neighbor);
        }
    }
}

void pdfs(const vector<vector<int>> &adjacencyList) {
    vector<bool> visited(adjacencyList.size(), false);

    for (int vertex = 0; vertex < adjacencyList.size(); ++vertex) {
        if (!visited[vertex]) {
            dfs(adjacencyList, visited, vertex);
        }
    }
}

int main() {
    const int numberOfVertices = 6;
    vector<vector<int>> adjacencyList(numberOfVertices);
    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};

    for (const auto &edge : edges) {
        edgeAdd(adjacencyList, edge[0], edge[1]);
    }

    cout << "DFS traversal:" << endl;
    pdfs(adjacencyList);

    return 0;
}
