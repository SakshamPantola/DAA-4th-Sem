#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF 1e9

void floydWarshall(vector<vector<int>>& dist, int v) {
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int v;
    cin >> v;
    vector<vector<int>> dist(v, vector<int>(v));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            string val;
            cin >> val;
            if (val == "INF") dist[i][j] = INF;
            else dist[i][j] = stoi(val);
        }
    }
    floydWarshall(dist, v);
    return 0;
}