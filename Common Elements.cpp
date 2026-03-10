// You have been given two sorted integer arrays of size m and n. 
// Design an algorithm and implement it using a program to find list of 
// elements which are common to both. (Time Complexity = O(m+n)) 
// Input Format: 
// First line contains m (the size of first array). 
// Second line contains m space-separated integers describing first array. 
// Third line contains n (the size of second array). 
// Fourth line contains n space-separated integers describing second 
// array. 
// Output Format: 
// Output will be the list of elements which are common to both. 
// Sample I/O Problem:
// Input: Output: 
// 7 
// 10 10 34 55 
// 3476 1039851055 
// 12 
// 305534721034 1089 11 30 69 51



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m;
    if (!(cin >> m)) return 0;
    vector<int> arr1(m);
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }
    
    int n;
    cin >> n;
    vector<int> arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;
    vector<int> result;
    
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            result.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    for (int k = 0; k < result.size(); k++) {
        cout << result[k] << (k == result.size() - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}