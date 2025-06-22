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

const ll MOD = 998244353;

ll modpow(ll x, ll n, ll m) {
	if (n==0) return 1 % m;
	ll res = modpow(x, n/2, m);
	res = (res*res) % m;
	if (n%2) res = (res*x) % m;
	return res;
}


void solve() {
	ll n; cin >> n;
	vi k(n);
	vvi gifts(n);
	umi counts;

	for(ll i = 0; i<n; i++) {
		ll ki;
		cin >> ki;
		k[i] = ki;
		gifts[i].resize(ki);

		for(ll j = 0; j<ki; j++) {
			cin >> gifts[i][j];
			counts[gifts[i][j]]++;
		}
	}

	ll num = 0, den = 0;
	for(ll i = 0; i<n; i++) {
		ll inv_k = modpow(k[i], MOD-2, MOD);
		ll t = 0;
		for(auto g : gifts[i]) {
			t += counts[g];	
		}
		t = ((t % MOD) * inv_k) % MOD;
		num = (num + t) % MOD;
	}
	den = (n * n) % MOD;
	den = modpow(den, MOD-2, MOD);

	cout << (num * den) % MOD;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}