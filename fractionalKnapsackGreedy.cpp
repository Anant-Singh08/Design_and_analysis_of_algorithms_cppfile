#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Item {
    int profit, weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};
static bool compare(struct Item a, struct Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int N)
{

    sort(arr, arr + N, compare);
 
    double output = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            output += arr[i].profit;
        }
        else {
            output
                += arr[i].profit
                   * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return output;
}


int main()
{
    int W = 75;
    Item arr[] = { { 70, 20 }, { 80, 30 }, { 90, 40 } };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << fractionalKnapsack(W, arr, N);
    return 0;
}
