/* Question 3: Pairs with Difference K
Given an array of n positive integers, design an algorithm and implement it using a program 
to find whether there exists a pair of elements such that their difference is equal to a given 
number K. 
Also, find the total number of such pairs for each test case.
(Time Complexity = O(n log n))
*/

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

    // Sorting the array to use two-pointer approach
    sort(arr.begin(), arr.end());

    int count = 0;
    int i = 0;
    int j = 1;

    while (j < n) {
        int diff = arr[j] - arr[i];

        if (diff == k) {
            count++;
            i++;
            j++;
        } else if (diff < k) {
            j++;
        } else {
            i++;
        }

        // Pointer i and j should not be same
        if (i == j) j++;
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}