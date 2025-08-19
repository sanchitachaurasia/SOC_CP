#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,ll>>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    // dist[node] will hold up to k shortest distances found so far to this node
    vector<vector<ll>> dist(n+1);

    // Min-heap for states: (cost, node)
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.emplace(0, 1);
    dist[1].push_back(0);

    vector<ll> answers;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        // If we reached target n and have k distances, output and stop
        if (u == n) {
            answers.push_back(cost);
            if ((int)answers.size() == k) break;
        }

        // Explore neighbors
        for (auto &[v, w] : graph[u]) {
            ll new_cost = cost + w;

            // If we can add this new_cost to dist[v] (less than k distances stored or smaller than worst)
            if ((int)dist[v].size() < k) {
                dist[v].push_back(new_cost);
                pq.emplace(new_cost, v);
            } else if (new_cost < dist[v].back()) {
                // Replace the worst with new_cost (since vector is not sorted, sort before checking)
                dist[v].push_back(new_cost);
                sort(dist[v].begin(), dist[v].end());
                dist[v].pop_back(); // remove worst
                pq.emplace(new_cost, v);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << answers[i] << " ";
    }
    cout << "\n";

    return 0;
}
