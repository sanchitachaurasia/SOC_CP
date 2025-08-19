#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(x) for (int i = 0; i < (x); ++i)
#define in(x) for (auto &i : x)
#define chmin(a, b) (a = min((a), (b)))
#define chmax(a, b) (a = max((a), (b)))
#define vsort(v) sort(all(v))
#define print(x) for (auto i : x) cout << i << " "; cout << endl;
#define take(x) for (int i = 0; i < n; ++i) cin >> x[i];
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endlc '\n'
#define lb lower_bound
#define ub upper_bound
#define uniq(v) v.erase(unique(all(v)), v.end())
const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    vector<vector<int>> dp(n, vector<int>(m + 2, 0));

    if (x[0] == 0) {
        for (int j = 1; j <= m; ++j) dp[0][j] = 1;
    } else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1]) % MOD + dp[i - 1][j + 1]) % MOD;
            }
        } else {
            int j = x[i];
            dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1]) % MOD + dp[i - 1][j + 1]) % MOD;
        }
    }

    int result = 0;
    for (int j = 1; j <= m; ++j) {
        result = (result + dp[n - 1][j]) % MOD;
    }
    cout << result << endl;
}
