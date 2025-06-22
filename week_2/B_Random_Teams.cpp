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

ll c2(ll x) {
	if (x < 2) return 0;
	// prevent overflow
	if (x % 2) return ((x-1)/2) * x;
	else return (x / 2) * (x-1);
}

void solve() {
	ll m, n; cin >> n >> m;
	ll m_old = m;

	if (m == n) {
		cout << "0 0";return;
	}
	
	ll kmin = 0;

	// for k_min, split with min std devn, for k_max, split as 1 1 ... (n-m+1)

	ll q = n / m;
	ll r = n % m;

	kmin += (r ? r * c2(q + 1) : 0);

	kmin += (m - r) * c2(q);


	ll kmax = c2(n - m_old + 1);

	cout << kmin << " " << kmax;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}