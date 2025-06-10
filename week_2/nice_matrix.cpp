#include <bits/stdc++.h>
using namespace std;

int median_cost(vector<int>& vals) {
    sort(vals.begin(), vals.end());
    int median = vals[vals.size() / 2];
    int cost = 0;
    for (int v : vals) {
        cost += abs(v - median);
    }
    return cost;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        
        long long total_cost = 0;
        
        for (int i = 0; i <= (n - 1) / 2; ++i) {
            for (int j = 0; j <= (m - 1) / 2; ++j) {
                vector<int> vals;
                
                // collect all symmetric positions
                vals.push_back(a[i][j]);
                if (i != n - i - 1) vals.push_back(a[n - i - 1][j]);
                if (j != m - j - 1) vals.push_back(a[i][m - j - 1]);
                if (i != n - i - 1 && j != m - j - 1)
                    vals.push_back(a[n - i - 1][m - j - 1]);
                
                total_cost += median_cost(vals);
            }
        }
        cout << total_cost << "\n";
    }
    
    return 0;
}
