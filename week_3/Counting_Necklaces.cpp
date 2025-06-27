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

const ll MAXN = 1e6+5;
const ll M = 1e9+7;

ll phi[MAXN];

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
	// idea: burnside's lemma
	// https://cp-algorithms.com/combinatorics/burnside.html
	// |classes| = 1/|G| sum over all pi in G (no. of fixed points in pi)
	// or, sum over all points (no. of permutations which preserve it)
	
	// we consider each pi to have C(pi) disjoint cycles
	// if f is a fixed point for pi, each cycle must have all elements constant
	// we choose from k elements so in the summation each term of k^C(pi)

	// now for a necklace, we can treat a group of all pi to be that of
	// all i-step rotations ie a_j -> a_{j+i % n}, where i=0,...n-1
	// for pi_i, len of each cycle is n/gcd(n,i) so C(pi_i) = gcd(n, i)

	// answer = 1/n sum over i=1..n of k^gcd(n,i)

	// alt sum over divisors of n: 1/n sum over d|n of phi(n/d) k^d
	// because all gcd(n,i) = d for phi(n/d) numbers

	// compute totient upto n using sieve
	for(ll i = 1; i<MAXN; i++) phi[i] = i;
	for(ll i = 2; i<MAXN; i++) {
		if (phi[i] == i) {
			for(ll j = i; j<MAXN; j+=i) {
				phi[j] -= phi[j] / i;
			}
		}
	}

	ll n, k; cin >>n >>k;

	ll ans=0;
	for(ll d = 1; d<=n; d++) {
		if (n % d == 0) {
			ans = (ans + phi[d] * modpow(k, n / d, M)) % M;
		}
	}
	ans = (ans * modinv(n)) % M;

	cout << ans << nl;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}