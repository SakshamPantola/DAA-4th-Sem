/* Question: Given a graph, design an algorithm and implement it using a 
program to find if a graph is bipartite or not. (Hint: use BFS)
Input: Number of vertices V, Adjacency Matrix.
Output: 'Yes Bipartite' or 'Not Bipartite'.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1); // -1: uncolored, 0: color1, 1: color2

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < V; v++) {
                    if (adj[u][v] != 0) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int V;
    if (!(cin >> V)) return 0;

    vector<vector<int>> adj(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adj[i][j];
        }
    }

    if (isBipartite(V, adj)) 
        cout << "Yes Bipartite" << endl;
    else 
        cout << "Not Bipartite" << endl;

    return 0;
}

