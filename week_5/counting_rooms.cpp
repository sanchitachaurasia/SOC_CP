#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n, m;
vector<string> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 0, 1, 0}; // up, right, down, left
int dy[4] = {0, 1, 0, -1};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m &&
           grid[x][y] == '.' && !visited[x][y];
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (is_valid(nx, ny)) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int room_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (is_valid(i, j)) {
                dfs(i, j);
                room_count++;
            }
        }
    }

    cout << room_count << '\n';
    return 0;
}
