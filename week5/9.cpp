#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    // Distance matrix
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    // Set distance to self as 0
    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    // Read roads
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); // In case of multiple edges
        dist[b][a] = min(dist[b][a], c); // Undirected
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << '\n';
        else
            cout << dist[a][b] << '\n';
    }

    return 0;
}
