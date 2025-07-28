#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> indeg(n+1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graph[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)order.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int x : order) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
