#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n, m;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dirChar[4] = {'U', 'R', 'D', 'L'};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && 
           !visited[x][y] && grid[x][y] != '#';
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> start, end;

    // Read input & locate A and B
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    // BFS from A
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (is_valid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!visited[end.first][end.second]) {
        cout << "NO\n";
        return 0;
    }

    // Reconstruct path
    string path;
    pair<int, int> curr = end;
    while (curr != start) {
        auto [px, py] = parent[curr.first][curr.second];
        for (int dir = 0; dir < 4; ++dir) {
            if (px + dx[dir] == curr.first && py + dy[dir] == curr.second) {
                path.push_back(dirChar[dir]);
                break;
            }
        }
        curr = {px, py};
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';

    return 0;
}
