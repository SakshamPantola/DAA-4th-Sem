#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;

    sort(arr.begin(), arr.end());
    int count = 0, i = 0, j = 1;
    while (j < n) {
        int diff = arr[j] - arr[i];
        if (diff == k) {
            count++;
            i++;
            j++;
        } else if (diff < k) j++;
        else i++;
        if (i == j) j++;
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}