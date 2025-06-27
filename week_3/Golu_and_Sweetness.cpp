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

void solve() {
	ll n, q; cin >> n >> q;

	vi prime_sweetness_sum(n);
	ll curr_prime_sweetness = 0;

	for(ll i = 0; i<n; i++) {
		ll k; cin >> k;

		// totient(k) is prime iff k == 3 or 2^i with i>1
		if (k == 3 || (k > 2 && (k & (k-1)) == 0)) {
			++curr_prime_sweetness;
		}
		prime_sweetness_sum[i] = curr_prime_sweetness;
	}

	for(ll i = 0; i<q; i++) {
		ll l, r; cin >> l >> r;

		ll diff = (l == 1) ? 0 : prime_sweetness_sum[l-2];

		cout << prime_sweetness_sum[r-1] - diff << nl;
	}
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}