#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f(i, l, n) for(decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define vin(v,n) f(i,0,n) cin >> v[i];
#define vout(v,n) f(i,0,n) cout << v[i] << " "; cout<<nl;
#define dbg(x) cerr << #x << " = " << x << ", ";

using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll,ll>;
using vpi = vector<pi>;
using usi = unordered_set<ll>;
using si = set<ll>;
using msi = multiset<ll>;
using mi = map<ll,ll>;
using umi = unordered_map<ll,ll>;

const ll MOD = 1e9 + 7;

ll modpow(ll x, ll n, ll m) {
	if (n==0) return 1 % m;
	ll res = modpow(x, n/2, m);
	res = (res*res) % m;
	if (n%2) res = (res*x) % m;
	return res;
}

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll d = modpow(b, c, MOD-1);
	ll e = modpow(a, d, MOD);
	cout << e << '\n';
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}