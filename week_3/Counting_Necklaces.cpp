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
const ll MOD = 1e9 + 7;
const ll N = 1e6 + 2;
ll fact[N];

void computeFactorials(int n)
{
    fact[0] = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
ll powint(ll a, ll b)
{
    ll out = 1;
    a %= MOD;
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
ll fmod(ll x, ll y)
{
    ll a = fact[x];
    ll b = fact[x - y] * fact[y] % MOD;
    ll c = powint(b, MOD - 2);
    c = a * c % MOD;
    return c;
}

int main()
{

    fastio();
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    ans+=powint(k,n);
    for(int i=1;i<n)

    
   
    
}
