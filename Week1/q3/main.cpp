#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void solve() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> key;

    int comparisons = 0;
    int step = 2; 
    int prev = 0;
    int curr = 0;

    while (curr < n && arr[curr] < key) {
        comparisons++;
        prev = curr;
        curr += step;
    }

    bool found = false;
    for (int i = prev; i < min(curr + 1, n); i++) {
        comparisons++;
        if (arr[i] == key) {
            found = true;
            break;
        }
    }

    if (found) cout << "Present " << comparisons << endl;
    else cout << "Not Present " << comparisons << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}