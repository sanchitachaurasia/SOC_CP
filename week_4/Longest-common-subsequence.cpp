#include <bits/stdc++.h>
using namespace std;
#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
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
#define print(x)          \
    for (auto i : x)      \
        cout << i << " "; \
    cout << endl;
#define take(x)                 \
    for (int i = 0; i < n; ++i) \
        cin >> x[i];
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endlc '\n'
#define lb lower_bound
#define ub upper_bound
#define uniq(v) v.erase(unique(all(v)), v.end())
const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main()
{
    fastio();
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    a[0] = -1;
    b[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= m; ++j)
    {
        cin >> b[j];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    // state:dp[i][j]=> longest common subsequence from the first i values of first sequence and first j values of secons sequence...
    // but how we will calculate the common vector...
    // by defining x and y? how to mark those elements?
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // now if i have dp composition what does this composition means and can it help to calculatae common vector
    int i = n, j = m;
    vector<int> lcs;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            lcs.push_back(a[i]);
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    reverse(lcs.begin(), lcs.end());

    cout << dp[n][m] << endl;
    print(lcs);
}
