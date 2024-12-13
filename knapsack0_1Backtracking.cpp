#include <iostream>
using namespace std;

int knapsack(int values[], int weights[], int capacity, int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }
    if (weights[n - 1] > capacity) {
        return knapsack(values, weights, capacity, n - 1);
    } else {
        int include = values[n - 1] + knapsack(values, weights, capacity - weights[n - 1], n - 1);
        int exclude = knapsack(values, weights, capacity, n - 1);
        return max(include, exclude);
    }
}
int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int values[n], weights[n];
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int profit = knapsack(values, weights, capacity, n);
    cout << "Maximum value in knapsack = " << profit;
    return 0;
}
