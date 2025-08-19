#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, ll>>> adj(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;  // Already found a better path
        
        for (auto [v, cost] : adj[u]) {
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
        cout << dist[i] << " ";
    cout << "\n";
    
    return 0;
}
