#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items, int n) {
    sort(items.begin(), items.end(), compare);

    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            finalValue += items[i].value;
        } else {
            finalValue += items[i].value * ((double)W / (double)items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) cin >> items[i].value >> items[i].weight;
    cin >> W;
    cout << fractionalKnapsack(W, items, n) << endl;
    return 0;
}
