#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;
const int MAXN = 501;

long long dist[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    // Initialize distances
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = (i == j) ? 0 : INF;

    // Read roads
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c); // Since the roads are two-way
    }

    // Floyd-Warshall Algorithm
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Process queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) cout << -1 << '\n';
        else cout << dist[a][b] << '\n';
    }

    return 0;
}
