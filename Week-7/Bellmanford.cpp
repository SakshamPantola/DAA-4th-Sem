#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(vector<Edge>& edges, int v, int e, int src) {
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= v - 1; i++) {
        for (int j = 0; j < e; j++) {
            if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }

    bool negativeCycle = false;
    for (int j = 0; j < e; j++) {
        if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative weight cycle detected" << endl;
    } else {
        for (int i = 0; i < v; i++) {
            if (dist[i] == INT_MAX) cout << i + 1 << " : INF" << endl;
            else cout << i + 1 << " : " << dist[i] << endl;
        }
    }
}

int main() {
    int v;
    cin >> v;
    vector<Edge> edges;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                edges.push_back({i, j, weight});
            }
        }
    }
    int src;
    cin >> src;
    bellmanFord(edges, v, edges.size(), src - 1);
    return 0;
}