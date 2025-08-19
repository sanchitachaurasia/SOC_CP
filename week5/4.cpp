#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
int distance[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 1;  // include the start node

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build the graph
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // undirected graph
    }

    // Run BFS from node 1
    bfs(1);

    if (!visited[n]) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << distance[n] << "\n";
        vector<int> path;
        for (int at = n; at != 0; at = parent[at])
            path.push_back(at);
        reverse(path.begin(), path.end());
        for (int node : path)
            cout << node << " ";
        cout << "\n";
    }

    return 0;
}
