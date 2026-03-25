#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> key;

    int first = -1, last = -1;
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if (first == -1) {
        cout << "Key not present" << endl;
        return;
    }

    low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            last = mid;
            low = mid + 1;
        } else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    cout << key << " - " << (last - first + 1) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}