#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainOrder(vector<int>& p, int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));

    for (int cl = 2; cl < n; cl++) {
        for (int i = 1; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    cout << matrixChainOrder(p, n) << endl;
    return 0;
}