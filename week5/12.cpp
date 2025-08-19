#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b;
    long long c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }

    const long long INF = 1e15;
    vector<long long> dist(n+1, 0);
    vector<int> parent(n+1, -1);

    int cycle_start = -1;

    // Bellman-Ford: run n times to detect negative cycle
    for (int i = 0; i < n; i++) {
        cycle_start = -1;
        for (auto &e : edges) {
            if (dist[e.a] + e.c < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.c;
                parent[e.b] = e.a;
                cycle_start = e.b;
            }
        }
    }

    if (cycle_start == -1) {
        cout << "NO\n";  // no negative cycle found
    } else {
        // To ensure cycle_start is inside the cycle, move back n times
        for (int i = 0; i < n; i++) {
            cycle_start = parent[cycle_start];
        }

        vector<int> cycle;
        int v = cycle_start;
        do {
            cycle.push_back(v);
            v = parent[v];
        } while (v != cycle_start);
        cycle.push_back(cycle_start);

        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int node : cycle) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
