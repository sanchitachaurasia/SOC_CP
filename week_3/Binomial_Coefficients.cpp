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

void solve() {
    ll n;
    cin >> n;
    vpi input(n);

	// idea: compute as a! * (b!)^-1 * (a-b!)^-1
	// get maxn and precompute factorials and factorial inverses
	// in O(maxn) time

    ll maxn = 0;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        maxn = max(maxn, max(a, b));
		input[i] = {a,b};
    }
    ++maxn;

    vi fact(maxn);
    fact[0] = 1;
    for (ll i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % M;

    vi inv(maxn);
    inv[1] = 1;
    for (ll i = 2; i < maxn; i++) inv[i] = M - (ll)(M / i) * inv[M % i] % M;

    vi factinv(maxn);
    factinv[0] = 1;
    for (ll i = 1; i < maxn; i++) factinv[i] = (factinv[i - 1] * inv[i]) % M;

    ll a, b, res;

    for (ll i = 0; i < n; i++) {
        a = input[i].ff;
        b = input[i].ss;

        res = fact[a] * factinv[b] % M;
        res = res * factinv[a - b] % M;

        cout << res << nl;
    }
}

int main() {
    fastio ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}