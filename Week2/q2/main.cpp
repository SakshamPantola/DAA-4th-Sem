#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int k = 0; k < n; k++) {
        int i = 0, j = n - 1;
        while (i < j) {
            if (i == k) { i++; continue; }
            if (j == k) { j--; continue; }
            if (arr[i] + arr[j] == arr[k]) {
                cout << i + 1 << ", " << j + 1 << ", " << k + 1 << endl;
                return;
            } else if (arr[i] + arr[j] < arr[k]) i++;
            else j--;
        }
    }
    cout << "No sequence found." << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}