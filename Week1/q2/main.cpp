#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> key;

    int low = 0, high = n - 1, comparisons = 0;
    bool found = false;
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            found = true;
            break;
        } else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
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