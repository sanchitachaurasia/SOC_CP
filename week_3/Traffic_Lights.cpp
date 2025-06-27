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
	ll n, x; cin >> x >> n;
	// VECTOR (MANUALLY SORTED USING binsearch) GIVES TLE
	// SO USING ORDERED [MULTI]SET

	// idea:
	// store light posns in order
	// when a new posn is added, one difference is removed amd two are added
	// the removed diff is that of the two light posns surrounding newly added posn
	// we can store these in ordered containers with (log n) insertion/removal
	// do these for n elements
	// overall, n log n which is good enough

	si lights = {0, x};
	msi gaps = {x};

	for(ll i = 0; i<n; i++) {
		ll posn; cin >> posn;
		
		auto it1 = lights.upper_bound(posn);
		auto it2 = it1; --it2;
		
		ll prev_diff = (*it1 - *it2);
		
		gaps.erase(gaps.find(prev_diff));
		
		gaps.insert(*it1 - posn);
		gaps.insert(posn - *it2);
		lights.insert(posn);  // do this after

		// for(auto x : lights) cerr << x << " ";
		// cerr << "| ";

		// for(auto x : gaps) cerr << x << " ";
		// cerr << nl;

		cout << *(--gaps.end()) << " ";
	}

}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}