#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read the roads
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Find connected components
    vector<int> reps; // representatives of components
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            reps.push_back(i);
            dfs(i);
        }
    }

    // Output
    cout << reps.size() - 1 << '\n';
    for (size_t i = 1; i < reps.size(); ++i) {
        cout << reps[i - 1] << " " << reps[i] << '\n';
    }

    return 0;
}
