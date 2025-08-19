#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int team[MAXN]; // 0: unassigned, 1 or 2: team number

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (team[v] == 0) {
                team[v] = 3 - team[u]; // switch between 1 and 2
                q.push(v);
            } else if (team[v] == team[u]) {
                return false; // same team as neighbor => not bipartite
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build the graph
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Check each connected component
    for (int i = 1; i <= n; ++i) {
        if (team[i] == 0) {
            if (!bfs(i)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    // Output team assignments
    for (int i = 1; i <= n; ++i) {
        cout << team[i] << ' ';
    }
    cout << '\n';

    return 0;
}
