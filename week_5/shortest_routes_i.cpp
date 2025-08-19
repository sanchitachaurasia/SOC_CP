#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1); // (destination, cost)
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[1] = 0;
    pq.emplace(0, 1); // (distance, node)

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, cost] : adj[u]) {
            if (dist[v] > d + cost) {
                dist[v] = d + cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
