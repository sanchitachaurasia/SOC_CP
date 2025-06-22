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

#define F first
#define S second

void solve() {
	ll t, n; cin >> n;
	
	// idxs stores for every number t in 0...n-1, (t) -> {first index of t+1, second index of t+1} as (i_t, j_t)

	// since for every index at of (t) there must be one person there
	// we greedily choose to send person at i_t-1 to i_t and j_t-1 to j_t or vice versa
	// whichever is better

	vector<bool> seen(n, 0);
	vpi idxs(n);

	for(ll i = 0; i<2*n; i++) {
		cin >> t;
		if (seen[t-1]) idxs[t-1].S = i;
		else seen[t-1] = idxs[t-1].F = i;
	}

	ll res = idxs[0].F + idxs[0].S;

	for (ll i = 1; i < n; i++) {
		res += min(
			abs(idxs[i].F - idxs[i-1].F) + abs(idxs[i].S - idxs[i-1].S),
			abs(idxs[i].F - idxs[i-1].S) + abs(idxs[i].S - idxs[i-1].F)
		);
	}

	cout << res;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}