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

const int N = 2e6 + 5;
long long fact[N];

void computeFactorials()
{
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
ll powint(ll a, ll b)
{
    ll out = 1;
    while (b)
    {
        if (b & 1)
        {
            out = (out * a) % MOD;
        }
        b>>=1;
        a=(a*a%MOD);

    }
    return out;
}


int main()
{
    computeFactorials();
    fastio();
    
    
        ll n,k;
        cin>>n>>k;
        n+=k-1;
        ll a=fact[n];
        ll b=fact[k]*fact[n-k]%MOD;
        ll c=powint(b,MOD-2);
        ll d=a*c%MOD;
        cout<<d<<endlc;


    }
  
