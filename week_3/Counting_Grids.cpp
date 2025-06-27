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
#define rep(x, i) for (int i = 0; i < (x); ++i)
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
ll powint(ll a, ll b)
{
    b = b % (MOD - 1);
    ll out = 1;
    while (b)
    {
        if (b & 1)
        {
            out = (out * a) % MOD;
        }
        b >>= 1;
        a = (a * a % MOD);
    }
    return out;
}

int main()
{
    fastio();
    ll n;
    cin >> n;
    ll k = n * n;
    if (n == 1)
    {
        cout << 2 << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << 6 << endl;
        return 0;
    }
    ll b, c, a = powint(2, k - 2);
    if (n % 2 == 1)
    {
        b = powint(2, k / 2 - 1);
        c = powint(2, k / 4 - 1);
    }
    else
    {
        b = powint(2, k / 2 - 2);
        c = powint(2, k / 4 - 2);
    }
    ll ans = a + b + 2 * c;
    cout << ans % MOD;
}