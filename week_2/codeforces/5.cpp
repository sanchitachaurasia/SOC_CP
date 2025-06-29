#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        long long total = 0;

        for (int i = 0; i <= n / 2; ++i) {
            for (int j = 0; j <= m / 2; ++j) {
                vector<int> vals;

                // collect symmetric positions
                vals.push_back(a[i][j]);
                if (i != n - 1 - i) vals.push_back(a[n - 1 - i][j]);
                if (j != m - 1 - j) vals.push_back(a[i][m - 1 - j]);
                if (i != n - 1 - i && j != m - 1 - j) vals.push_back(a[n - 1 - i][m - 1 - j]);

                sort(vals.begin(), vals.end());
                int median = vals[vals.size() / 2];

                for (int v : vals)
                    total += abs(v - median);
            }
        }

        cout << total << '\n';
    }
}
