vector<int> adj[N];
bool visited[N];
int parent[N];
int start = -1, end = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    for (int nbr : adj[node]) {
        if (nbr == par) continue;
        if (visited[nbr]) {
            start = nbr;
            end = node;
            return true;
        }
        parent[nbr] = node;
        if (dfs(nbr, node)) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) {
            vector<int> cycle = {start};
            for (int v = end; v != start; v = parent[v])
                cycle.push_back(v);
            cycle.push_back(start);
            reverse(cycle.begin(), cycle.end());
            cout << cycle.size() << "\n";
            for (int c : cycle) cout << c << " ";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
