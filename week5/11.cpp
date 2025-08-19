#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e15;

struct Edge {
    int to;
    ll cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;
    vector<vector<Edge>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    // dist[node][used_coupon?]
    vector<vector<ll>> dist(n+1, vector<ll>(2, INF));
    dist[1][0] = 0;

    // Min-heap: (distance, node, coupon_used_flag)
    using T = tuple<ll,int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(0, 1, 0);

    while (!pq.empty()) {
        auto [d, u, used] = pq.top(); pq.pop();
        if (dist[u][used] < d) continue;

        for (auto &e : graph[u]) {
            int v = e.to;
            ll c = e.cost;

            // Case 1: Not used coupon yet, pay full price
            if (!used && dist[v][0] > d + c) {
                dist[v][0] = d + c;
                pq.emplace(dist[v][0], v, 0);
            }
            // Case 2: Use coupon on this edge (if not used yet)
            if (!used) {
                ll new_cost = d + c / 2;  // floor automatically with integer division
                if (dist[v][1] > new_cost) {
                    dist[v][1] = new_cost;
                    pq.emplace(dist[v][1], v, 1);
                }
            }
            // Case 3: Coupon already used, pay full price
            if (used && dist[v][1] > d + c) {
                dist[v][1] = d + c;
                pq.emplace(dist[v][1], v, 1);
            }
        }
    }

    // Result is minimum cost to reach n with or without coupon used
    cout << min(dist[n][0], dist[n][1]) << "\n";

    return 0;
}
