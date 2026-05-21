#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int>& dist, vector<bool>& visited, int v) {
    int minVertex = -1;
    for (int i = 0; i < v; i++) {
        if (!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(vector<vector<int>>& graph, int src, int v) {
    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);
    dist[src] = 0;

    for (int i = 0; i < v - 1; i++) {
        int u = findMinVertex(dist, visited, v);
        if (u == -1) break;
        visited[u] = true;

        for (int j = 0; j < v; j++) {
            if (graph[u][j] != 0 && !visited[j]) {
                if (dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    for (int i = 0; i < v; i++) {
        if (dist[i] == INT_MAX) cout << i + 1 << " : INF" << endl;
        else cout << i + 1 << " : " << dist[i] << endl;
    }
}

int main() {
    int v;
    cin >> v;
    vector<vector<int>> graph(v, vector<int>(v));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) cin >> graph[i][j];
    }
    int src;
    cin >> src;
    dijkstra(graph, src - 1, v);
    return 0;
}