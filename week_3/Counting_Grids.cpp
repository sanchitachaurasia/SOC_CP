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

const ll M=1e9+7;

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

ll modinv(ll a) {return modpow(a, M-2, M); }

void solve() {
	ll n; cin >> n;

	// idea: burnside's lemma
	// G = 0deg rotn, 90deg, 180deg, 270deg
	// I(pi) are resp.
	// all nxn grids, all quarter grids, half grids, quarter (same as 90)

	ll I_0 = n*n;
	ll I_90 = 1, I_180 = 1;

	if (n > 1 && (n&1)) {
		I_90 = ((n+1) / 2) * ((n-1) / 2) + 1;  // 1 for middle square
		I_180 = ((n+1) / 2) * (n-1) + 1;  // 1 for middle square
	}
	else if (!(n&1)) {
		I_90 = (n / 2) * (n / 2);
		I_180 = (n / 2) * n;
	}
	ll ans = modpow(2, I_0, M);
	ans = (ans + 2 * modpow(2, I_90, M)) % M;
	ans = (ans + modpow(2, I_180, M)) % M;
	ans = (ans * modinv(4)) % M;
	cout<<ans <<nl;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}