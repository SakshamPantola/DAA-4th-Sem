/* Question: Given a (directed/undirected) graph, design an algorithm and 
implement it using a program to find if a path exists between two given 
vertices or not. (Hint: use DFS)
Input: Number of vertices V, Adjacency Matrix, Source vertex, Destination vertex.
Output: 'Yes Path Exists' or 'No Such Path Exists'.
*/

#include <iostream>
#include <vector>

using namespace std;

bool hasPath(int curr, int dest, int V, vector<vector<int>>& adj, vector<bool>& visited) {
    if (curr == dest) return true;
    visited[curr] = true;

    for (int i = 0; i < V; i++) {
        if (adj[curr][i] != 0 && !visited[i]) {
            if (hasPath(i, dest, V, adj, visited)) return true;
        }
    }
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

    int src, dest;
    cin >> src >> dest;

    vector<bool> visited(V, false);
    if (hasPath(src, dest, V, adj, visited)) 
        cout << "Yes Path Exists" << endl;
    else 
        cout << "No Such Path Exists" << endl;

    return 0;
}

