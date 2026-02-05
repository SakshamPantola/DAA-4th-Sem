#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, key, comparisons = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> key;

    bool found = false;
    for (int i = 0; i < n; i++) {
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