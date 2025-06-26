#include <bits/stdc++.h>
using namespace std;

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define pb push_back
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forr(i, l, n) \
    for (decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define vin(v, n) forr(i, 0, n) cin >> v[i];
#define vout(v, n)                     \
    forr(i, 0, n) cout << v[i] << " "; \
    cout << nl;
#define dbg(x) cerr << #x << " = " << x << ", ";

using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using usi = unordered_set<ll>;
using si = set<ll>;
using msi = multiset<ll>;
using mi = map<ll, ll>;
using umi = unordered_map<ll, ll>;

#define yes          \
    cout << "YES\n"; \
    return
#define no          \
    cout << "NO\n"; \
    return

#define ff first
#define ss second

const ll M = 1e9 + 7;

ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    ll power = a;

    a %= m;
    b %= (m - 1);  // assuming prime m and gcd(a,m)=1

    while (b) {
        if (b & 1) {
            res = res * power % m;
        }
        power = (power * power) % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    // answer is n+m-1 C m
    // use min(n-1, m) in denominator

    ll a = n - 1 + m;
    ll b = min(n - 1, m);
	ll c = a - b;

    ll fact_b = 1;
    for (ll i = 1; i <= b; i++) fact_b = (fact_b * i) % M;

    ll fact_c = fact_b;
    for (ll i = b+1; i <= c; i++) fact_c = (fact_c * i) % M;

    ll fact_a = fact_c;
    for (ll i = c+1; i <= a; i++) fact_a = (fact_a * i) % M;

    ll res = fact_a * (modpow(fact_b, M - 2, M)) % M;
	res = (res * modpow(fact_c, M-2, M)) % M;
    cout << res << nl;
}

int main() {
    fastio ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}