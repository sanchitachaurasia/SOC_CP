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

void solve() {
	ll n; cin >> n;

	ll max_prime = 0;
	vi primes(n), pows(n);

	for(ll i = 0; i<n; i++) {
		cin >> primes[i] >> pows[i];
		max_prime = max(max_prime, primes[i]);
	}

	ll numdiv = 1;
	// num divisors
	for (auto e : pows)
		numdiv = (numdiv * (1 + e)) % M;
	cout << numdiv << " ";

	// sum
	vi inv(max_prime);
	inv[1] = 1;
	for(ll i = 2; i < max_prime; i++) inv[i] = M - (ll)(M/i) * inv[M%i] % M;

	ll sumdiv = 1;
	for(ll i = 0; i < n; i++) {
		sumdiv = (sumdiv * (modpow(primes[i], pows[i] + 1, M) - 1)) % M;
		sumdiv = (sumdiv * inv[primes[i] - 1]) % M;
	}
	cout << sumdiv << " ";

	// prod = n ^ (d(n)/2)
	ll proddiv = 1;

	// we need numdiv BUT NOT mod M, instead mod M-1
	// NOTE: since gcd(2, M-1) != 1, you cannot divide after modulo
	// must divide as early as possible

	bool found_odd_pow = false;
	ll odd_pow_idx = -1;
	ll d = 1;
	for (ll i = 0; i < n; i++) {
		ll e = pows[i];
		if (!found_odd_pow && e % 2) {
			d = ((1 + e) / 2) % (M - 1);
			
			found_odd_pow = true;
			odd_pow_idx = i;
			break;
		}
	}

	// num divisors
	for (ll i = 0; i < n; i++) {
		ll e = pows[i];
		if (i == odd_pow_idx) continue;
		d = (d * (1 + e)) % (M - 1);
	}

	for(ll i = 0; i < n; i++) {
		// half each exponent if theyre all even
		ll e = found_odd_pow ? pows[i] : pows[i] / 2;

		proddiv = (proddiv * modpow(primes[i], e * d , M)) % M;
	}
	cout << proddiv << nl;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}