#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        long long total_cost = 0;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = 0; j < (m + 1) / 2; ++j) {
                // Collect the symmetric positions
                vector<int> vals;
                vals.push_back(a[i][j]);
                if (i != n - 1 - i) vals.push_back(a[n - 1 - i][j]);
                if (j != m - 1 - j) vals.push_back(a[i][m - 1 - j]);
                if (i != n - 1 - i && j != m - 1 - j)
                    vals.push_back(a[n - 1 - i][m - 1 - j]);

                sort(vals.begin(), vals.end());
                int median = vals[vals.size() / 2];
                for (int val : vals)
                    total_cost += abs(val - median);
            }
        }
        cout << total_cost << '\n';
    }
    return 0;
}
