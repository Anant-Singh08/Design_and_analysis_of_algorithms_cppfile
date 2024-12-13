#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mincost(int city, vector<vector<int>> &graph, vector<bool> &visited,
            int cost, int count, int start, int N) {
    if (count == N && graph[city][start]) {
        return cost + graph[city][start];
    }
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[city][i]) {
            visited[i] = true;
            int temp = mincost(i, graph, visited, cost + graph[city][i], count + 1, start, N);
            ans = min(ans, temp);
            visited[i] = false;
        }
    }
    return ans;
}

int tspbb(vector<vector<int>> &graph, int N) {
    vector<bool> visited(N, false);
    visited[0] = true;
    return mincost(0, graph, visited, 0, 1, 0, N);
}

int main() {
    int N = 5;
    vector<vector<int>> graph = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 25, 30},
        {15, 35, 0, 30, 5},
        {20, 25, 30, 0, 10},
        {25, 30, 5, 10, 0}
    };
    int result = tspbb(graph, N);
    cout << "Minimum cost = " << result ;
    return 0;
}
