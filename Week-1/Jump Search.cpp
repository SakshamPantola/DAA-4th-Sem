/* Question 3: Jump Search
Given a sorted array of n positive integers, design an algorithm and implement it using a program 
to find whether a given key element is present in the array or not. 
The algorithm should make fewer comparisons than linear search. 
Also, find the total number of comparisons for each test case.
(Time Complexity = O(√n))
*/

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
    int m = sqrt(n); // Jump size
    int prev = 0;
    int curr = 0;

    // Jumping blocks to find the potential range
    while (curr < n && arr[curr] < key) {
        comparisons++;
        prev = curr;
        curr += m;
    }

    // Linear search in the identified block
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
    while (t--) {
        solve();
    }
    return 0;
}