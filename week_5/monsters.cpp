#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<string> grid;
vector<vector<int>> monster_time, player_time;
vector<vector<pair<int, int>>> parent;
queue<pair<int, int>> mq, pq;

int dx[] = {-1, 1, 0, 0}; // U D L R
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    monster_time.assign(n, vector<int>(m, INF));
    player_time.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> start;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                mq.push({i, j});
                monster_time[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    // BFS for monster arrival times
    while (!mq.empty()) {
        auto [x, y] = mq.front(); mq.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (is_valid(nx, ny) && monster_time[nx][ny] == INF) {
                monster_time[nx][ny] = monster_time[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }

    // BFS for player path
    pq.push(start);
    player_time[start.first][start.second] = 0;

    while (!pq.empty()) {
        auto [x, y] = pq.front(); pq.pop();
        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            // Reached border
            cout << "YES\n";
            vector<char> path;
            pair<int, int> cur = {x, y};
            while (cur != start) {
                auto [px, py] = parent[cur.first][cur.second];
                for (int d = 0; d < 4; ++d) {
                    if (px + dx[d] == cur.first && py + dy[d] == cur.second) {
                        path.push_back(dir[d]);
                        break;
                    }
                }
                cur = {px, py};
            }
            reverse(path.begin(), path.end());
            cout << path.size() << "\n";
            for (char c : path) cout << c;
            cout << "\n";
            return 0;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (is_valid(nx, ny) && player_time[nx][ny] == INF) {
                int arrival = player_time[x][y] + 1;
                if (arrival < monster_time[nx][ny]) {
                    player_time[nx][ny] = arrival;
                    parent[nx][ny] = {x, y};
                    pq.push({nx, ny});
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}
