/* Question: Given a directed graph, design an algorithm and implement it 
using a program to find whether cycle exists in the graph or not.
Input: Number of vertices V, Adjacency Matrix.
Output: 'Yes Cycle Exists' or 'No Cycle Exists'.
*/

#include <iostream>
#include <vector>

using namespace std;

bool checkCycle(int u, int V, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;

    for (int v = 0; v < V; v++) {
        if (adj[u][v] != 0) {
            if (!visited[v] && checkCycle(v, V, adj, visited, recStack))
                return true;
            else if (recStack[v])
                return true;
        }
    }

    recStack[u] = false;
    return false;
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

    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    bool cycleFound = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (checkCycle(i, V, adj, visited, recStack)) {
                cycleFound = true;
                break;
            }
        }
    }

    if (cycleFound) 
        cout << "Yes Cycle Exists" << endl;
    else 
        cout << "No Cycle Exists" << endl;

    return 0;
}
