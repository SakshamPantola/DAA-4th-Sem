// l. 
// Given an unsorted array of alphabets containing duplicate 
// elements. Design an algorithm and implement it using a program to find 
// 5. | which alphabet has maximum number of occurrences and 
// print it. (Time Complexity = O(n)) (Hint: Use counting sort) 
// Input Format:The first line contains number of test cases, T. For each test case, 
// there will be two input lines. First line contains n (the size of array). 
// Second line contains space-separated integers describing array. 
// Output: 
// The output will have T number of lines. 
// For each test case, output will be the array element which has 
// maximum occurrences and its total number of occurrences. 
// If 
// no duplicates are present (i.e. all the elements occur only once), 
// output should be “No Duplicates Present”. 
// Sample 1/O Problem I: 
// Input: Output: 
// 3 
// 10 
// a-3 
// No Duplicates Present 
// aedwadqgafp 1-4 
// 15 
// rkpgvyumagadjcze 
// 20 
// gtllitcwawglcwdsaavcl 




#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        freq[c - 'a']++;
    }
    
    int max_freq = 0;
    char max_char = 'a';
    for (int i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_char = i + 'a';
        }
    }
    
    if (max_freq <= 1) {
        cout << "No Duplicates Present\n";
    } else {
        cout << max_char << "-" << max_freq << "\n";
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

