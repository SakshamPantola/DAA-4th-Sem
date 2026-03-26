/* Question 1: Count Duplicates
Given a sorted array of positive integers containing duplicates, design an algorithm and 
implement it using a program to find whether a given key element is present or not. 
If present, find total number of copies of the given key. (Time Complexity = O(log n))
*/

#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> key;

    int first = -1, last = -1, l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key) { first = m; r = m - 1; }
        else if (arr[m] < key) l = m + 1;
        else r = m - 1;
    }
    if (first == -1) { cout << "Key not present" << endl; return; }
    l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key) { last = m; l = m + 1; }
        else if (arr[m] < key) l = m + 1;
        else r = m - 1;
    }
    cout << key << " - " << (last - first + 1) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}