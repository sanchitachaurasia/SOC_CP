#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int n, m;
char grid[MAX][MAX];
pair<int, int> parent[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char dirChar[4] = {'L', 'R', 'U', 'D'};

int monsterTime[MAX][MAX];

bool isBoundary(int x, int y) {
    return x == 0 || y == 0 || x == n-1 || y == m-1;
}

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
}

int main() {
    cin >> n >> m;
    queue<pair<int, int>> mq, pq;

    pair<int, int> start;

    // Input
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            monsterTime[i][j] = INT_MAX;
            if (grid[i][j] == 'M') {
                mq.push({i, j});
                monsterTime[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    // BFS for monsters
    while (!mq.empty()) {
        auto [x, y] = mq.front(); mq.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (isValid(nx, ny) && monsterTime[nx][ny] > monsterTime[x][y] + 1) {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }

    // BFS for player
    pq.push(start);
    visited[start.first][start.second] = true;
    map<pair<int,int>, char> moveDir;

    int level[MAX][MAX];
    level[start.first][start.second] = 0;

    pair<int, int> end = {-1, -1};

    while (!pq.empty()) {
        auto [x, y] = pq.front(); pq.pop();
        if (isBoundary(x, y)) {
            end = {x, y};
            break;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (isValid(nx, ny) && !visited[nx][ny] && level[x][y] + 1 < monsterTime[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                moveDir[{nx, ny}] = dirChar[d];
                level[nx][ny] = level[x][y] + 1;
                pq.push({nx, ny});
            }
        }
    }

    if (end.first == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string path;
        pair<int, int> curr = end;
        while (curr != start) {
            path += moveDir[curr];
            curr = parent[curr.first][curr.second];
        }
        reverse(path.begin(), path.end());
        cout << path.length() << "\n" << path << "\n";
    }

    return 0;
}
