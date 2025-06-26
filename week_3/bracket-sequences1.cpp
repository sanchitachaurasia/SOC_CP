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

const int MAX_A = 2*1e6 + 1;
const int MAX_B=1e6+1;
vector<ll> fact(MAX_A);
vector<ll> inv_fact(MAX_B);

ll modpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precalculate() {
    fact[0] = 1;
    for (int i = 1; i < MAX_A; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX_B - 1] = modpow(fact[MAX_B - 1], MOD - 2);
    for (int i = MAX_B - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

int ans(int n){
    int inv_extra=modpow(n+1,MOD-2);
    return fact[2*n]%MOD * inv_fact[n]%MOD * inv_fact[n]%MOD * inv_extra%MOD;
}

int main(){
    fastio();
    int n=1;
    cin>>n;
    precalculate();
    if(n%2==1){cout<<0<<endl; return 0;}
    else {
        cout<<ans(n/2)<<endl;
    }
}
