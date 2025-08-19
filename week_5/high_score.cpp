#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        edges.push_back({a, b, -x}); // invert weight
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    // Bellman-Ford: Relax edges n-1 times
    for (int i = 1; i < n; ++i) {
        for (auto [a, b, x] : edges) {
            if (dist[a] < INF && dist[a] + x < dist[b]) {
                dist[b] = dist[a] + x;
            }
        }
    }

    // Detect negative cycle (i.e., positive cycle in original graph)
    vector<bool> affected(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        for (auto [a, b, x] : edges) {
            if (dist[a] < INF && dist[a] + x < dist[b]) {
                dist[b] = -INF;
                affected[b] = true;
            }
            if (affected[a]) affected[b] = true;
        }
    }

    if (affected[n]) cout << -1 << "\n";
    else cout << -dist[n] << "\n"; // negate back
}
