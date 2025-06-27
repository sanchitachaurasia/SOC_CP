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

const ll M = 1e9+7;

umi inv;

ll modpow(ll a, ll b, ll m) {
	ll res = 1;
	ll power = a;

	a %= m;
	b %= (m-1); // assuming prime m and gcd(a,m)=1

	while(b) {
		if (b&1) {res = res * power % m;}
		power = (power * power) % m;
		b >>= 1;
	}
	return res;
}

ll modinv(ll a) {
	if (inv.count(a)) return inv[a];
	return (inv[a] = modpow(a, M-2, M));
}

void solve() {
	// simply n! / prod ci!
	// where ci is count of i-th char
	// NOT precomputing all inverses since it wont be necessary

	string s; cin >> s;
	vi cnts(26);
	ll n = s.size();
	for(char c: s) {
		++cnts[c-'a'];
	}

	vi fact(n+1);
	fact[0] = 1;
	for(ll i = 1; i<=n; i++) fact[i] = i * fact[i-1] % M;

	ll res = fact[n];
	for(auto c : cnts) {
		res = (res * modinv(fact[c])) % M;
	}

	cout << res << nl;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}