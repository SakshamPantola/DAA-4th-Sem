#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int shortestPathKEdges(vector<vector<int>>& graph, int u, int v, int k, int n) {
    if (k == 0 && u == v) return 0;
    if (k == 1 && graph[u][v] != 0) return graph[u][v];
    if (k <= 0) return INT_MAX;

    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (graph[u][i] != 0 && u != i && v != i) {
            int rec_res = shortestPathKEdges(graph, i, v, k - 1, n);
            if (rec_res != INT_MAX) {
                res = min(res, graph[u][i] + rec_res);
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }
    int src, dest, k;
    cin >> src >> dest >> k;

    int ans = shortestPathKEdges(graph, src - 1, dest - 1, k, n);
    if (ans == INT_MAX) cout << "No path weight found" << endl;
    else cout << "Weight of shortest path is " << ans << endl;
    return 0;
}