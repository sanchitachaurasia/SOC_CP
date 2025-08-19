#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input roads
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // Undirected graph
    }

    vector<int> representatives;

    // Find connected components
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            representatives.push_back(i);
            dfs(i);
        }
    }

    int k = representatives.size() - 1;
    cout << k << "\n";

    // Connect each component to the first
    for (int i = 1; i < representatives.size(); ++i) {
        cout << representatives[0] << " " << representatives[i] << "\n";
    }

    return 0;
}
