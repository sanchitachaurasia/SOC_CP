#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    fastio();
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = min({dp[i - 1][j] + 1,  // deletion
                            dp[i][j - 1] + 1,  // insertion
                            dp[i - 1][j - 1] + cost});  // replacement
        }
    }

    cout << dp[m][n] << '\n';
}

