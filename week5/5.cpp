#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int color[MAXN]; // 0 = unvisited, 1 or 2 = team number

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 1; // Start with team 1

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (color[v] == 0) {
                color[v] = 3 - color[u]; // Assign opposite team
                q.push(v);
            } else if (color[v] == color[u]) {
                return false; // Same team conflict
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input edges
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Try to color all components
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            if (!bfs(i)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    // Print the team assignment
    for (int i = 1; i <= n; ++i) {
        cout << color[i] << " ";
    }
    cout << "\n";

    return 0;
}
