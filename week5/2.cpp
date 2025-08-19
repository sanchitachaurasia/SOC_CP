#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAXN = 1000;
int n, m;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

// Directions: {dx, dy, move character}
int dx[] = {-1, 1, 0, 0}; // U D L R
int dy[] = {0, 0, -1, 1};
char moveChar[] = {'U', 'D', 'L', 'R'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m &&
           grid[x][y] != '#' && !visited[x][y];
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> start, end;

    // Input grid and find A and B
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
        auto [x, y] = q.front();
        q.pop();

        // Stop if we reached B
        if (make_pair(x, y) == end) break;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y}; // remember where we came from
                q.push({nx, ny});
            }
        }
    }

    // Reconstruct path
    if (!visited[end.first][end.second]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        string path;
        pair<int, int> curr = end;

        // Trace back from end to start
        while (curr != start) {
            pair<int, int> prev = parent[curr.first][curr.second];

            // Find direction
            for (int dir = 0; dir < 4; ++dir) {
                if (prev.first + dx[dir] == curr.first &&
                    prev.second + dy[dir] == curr.second) {
                    path.push_back(moveChar[dir]);
                    break;
                }
            }

            curr = prev;
        }

        reverse(path.begin(), path.end());
        cout << path.size() << "\n" << path << "\n";
    }

    return 0;
}
