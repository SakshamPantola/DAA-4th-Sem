// Given an unsorted array of integers, design an algorithm and 
// implement it using a program to find whether two elements exist such 
// that their sum is equal to the given key element. (Time Complexity = 
// O(n log n)) 
// Input Format: 
// The first line contains number of test cases, T. For each test case, 
// there will be two input lines. First line contains n (the size of array). 
// Second line contains space-separated integers describing array. Third 
// line contains key
// Output Format: 
// The output will have T number of lines. 
// For each test case, output will be the elements arr|i] and arr{j] such that 
// arr[i]+arr[j] = key if exist otherwise print '‘No Such Elements Exist”. 
// Sample 1/O Problem II: 
// Input: Output: 
// 2 
// 10 
// 10 40 
// No Such Element Exist 
// 64 28 97 40 1272 84 24 38 10 
// 50 
// 15 
// 56 10729129341456120113991294 
// 302 



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    
    sort(arr.begin(), arr.end());
    
    int i = 0, j = n - 1;
    bool found = false;
    
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == key) {
            cout << arr[i] << " " << arr[j] << "\n";
            found = true;
            break;
        } else if (sum < key) {
            i++;
        } else {
            j--;
        }
    }
    
    if (!found) {
        cout << "No Such Element Exist\n";
    }
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

