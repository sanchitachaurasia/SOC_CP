#include <bits/stdc++.h>
using namespace std;

const long long NEG_INF = LLONG_MIN / 2;

struct Edge {
    int a, b;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }

    // dist array to store max score, initialized to very small
    vector<long long> dist(n+1, NEG_INF);
    dist[1] = 0;

    // Bellman-Ford for max path:
    for (int i = 0; i < n-1; i++) {
        for (auto &e : edges) {
            if (dist[e.a] != NEG_INF && dist[e.a] + e.w > dist[e.b]) {
                dist[e.b] = dist[e.a] + e.w;
            }
        }
    }

    // Detect positive cycles reachable from 1 and can reach n
    vector<bool> affected(n+1, false);

    for (int i = 0; i < n-1; i++) {
        for (auto &e : edges) {
            if (dist[e.a] != NEG_INF && dist[e.a] + e.w > dist[e.b]) {
                dist[e.b] = dist[e.a] + e.w;
                affected[e.b] = true;  // Mark node as affected by a cycle
            }
            if (affected[e.a]) affected[e.b] = true;
        }
    }

    // If node n is affected by positive cycle, print -1
    if (affected[n]) {
        cout << -1 << "\n";
    } else {
        cout << dist[n] << "\n";
    }

    return 0;
}
