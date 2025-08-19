#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // BFS from node 1
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct path from n to 1
    vector<int> path;
    for (int u = n; u != -1; u = parent[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (int u : path) {
        cout << u << ' ';
    }
    cout << '\n';

    return 0;
}
