#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forr(i, l, n) for(decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define vin(v,n) forr(i,0,n) cin >> v[i];
#define vout(v,n) forr(i,0,n) cout << v[i] << " "; cout<<nl;
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

#define yes cout << "YES\n"; return
#define no cout << "NO\n"; return

#define ff first
#define ss second

const ll M = 1e9 + 7;

ll modpow(ll a, ll b, ll mod) {
	a %= mod;

	ll res = 1;
	ll power = a;
	while(b) {
		if (b & 1) res = (power * res) % mod;
		power = (power * power) % mod;
		b >>= 1;
	}

	return res;
}

void solve() {
	ll a, b; cin >> a >> b;

	// sum = prod (pi^(B*ei) - 1) * (pi - 1)^-1
	// for powers take mod M-1

	a %= M;
	if (a <= 1) {cout << a << nl; return;}

	b %= (M - 1);

	vi pi;
	vi ei;

	for(ll k = 2; k*k <= a; k++) {
		if (a % k == 0) {
			pi.push_back(k);
			
			ll e = 1;
			while (a /= k, a % k == 0)
				e++;

			ei.push_back(e);
		}
	}
	if (a > 1) {
		pi.push_back(a);
		ei.push_back(1);
	}

	// for(auto x : pi) cerr << x << " ";
	// cerr << nl;

	// for(auto x : ei) cerr << x << " ";
	// cerr << nl;

	// precompute inverses for pi-1
	// a^-1 = -k * r^-1
	// vi inv(pi.back());
	// inv[1] = 1;
	// for (ll i = 2; i < inv.size(); i++) { inv[i] = M - (ll)M/i * inv[M%i] % M; }


	// for(auto x : inv) cerr << x << " ";
	// cerr << nl;

	ll res = 1;
	for(ll i = 0; i < pi.size(); i++) {
		res = (res * (modpow(pi[i], (b * ei[i] + 1) % (M-1), M) + M - 1)) % M;
		// res = (res * inv[pi[i] - 1]) % M;
		res = (res * modpow(pi[i] - 1, M - 2, M)) % M;
	}

	cout << res << nl;

}

int main() {
	// #ifndef ONLINE_JUDGE

    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

	// #endif

	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}