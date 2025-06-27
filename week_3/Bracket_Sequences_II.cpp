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

#define zero cout<<"0\n";return

const ll MAXN = 1e6;
const ll M = 1e9+7;

ll fact[MAXN+1];

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

ll modinv(ll a) {return modpow(a, M-2, M);}

void solve() {
	ll n; cin >> n;
	string s; cin >> s;
	ll k = s.size();
	ll o = 0, c = 0, del = 0;

	if (n&1) {zero;}
	n/=2;

	for(auto d : s) {
		if (d == '(') {o++; del++;}
		else {c++; del--;}
		if (del < 0 ) {zero;}
	}

	if (o > n) {zero;}

	// idea: answer is
	// total no of brackets - no of invalid brackets
	// (2*n - k) choose (n - c)   -   (2*n - k) choose (n - c + 1)
	// same idea as in proof of 2n balanced parentheses = C_n
	// use k=o+c

	fact[0] = 1;
	for(ll i = 1; i<=2*n-k; i++) fact[i] = (fact[i-1] * i) % M;

	ll ans = (fact[2*n-k] * modinv(fact[n-o]) % M) * modinv(fact[n-c]) % M;
	ans -= (fact[2*n-k] * modinv(fact[n-o-1]) % M) * modinv(fact[n-c+1]) % M;
	ans = (ans + M) % M;

	cout << ans << nl;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}