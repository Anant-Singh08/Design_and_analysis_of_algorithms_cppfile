#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knap(const vector<int>& weights, const vector<int>& values, int w, int n) {

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0; 
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (weights[i - 1] <= j) { 
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j]; 
            }
        }
    }

    return dp[n][w];
}

int main() {
    vector<int> weights = {9, 12, 87, 9};
    vector<int> profits = {10, 20, 100, 90};
    int W = 10;
    int n = weights.size();

    int profit = knap(weights, profits, W, n);
    cout << "Max profit: " << profit << endl;

    return 0;
}
