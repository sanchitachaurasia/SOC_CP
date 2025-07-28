#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];

int startCycle = -1, endCycle = -1;

bool dfs(int u, int p) {
    visited[u] = true;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue; // Skip the edge back to parent
        if (visited[v]) {
            // Found a cycle
            startCycle = v;
            endCycle = u;
            return true;
        } else {
            if (dfs(v, u)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read input
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Run DFS from each unvisited node
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                break;
            }
        }
    }

    if (startCycle == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        // Reconstruct the cycle
        vector<int> cycle;
        cycle.push_back(startCycle);
        for (int v = endCycle; v != startCycle; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(startCycle);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int city : cycle) {
            cout << city << " ";
        }
        cout << "\n";
    }

    return 0;
}
