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

void solve() {
	ll n; cin >> n;
	vpi ints(n);
	vi sorted(n);

	for(ll i = 0; i<n; i++) {
		sorted[i] = i;
		cin >> ints[i].first;
		cin >> ints[i].second;
	}

	sort(all(sorted), [&](ll a, ll b){
		if (ints[a].first == ints[b].first) return ints[a].second > ints[b].second;
		return ints[a].first < ints[b].first;
	});

	// maintain ordered containers to track number of r's <= current r
	vi max_rs;
	vi min_rs;

	vi contains(n, 0);
	vi contained(n, 0);

	for(ll i = 0; i < n; i++) {
		ll idx = sorted[i];
		ll r = ints[idx].second;

		// cerr << idx << ";" << r << ";";
		// for(auto i : max_rs) cerr << i << ",";
		// cerr << ";" << distance(lower_bound(all(max_rs), r), max_rs.end());
		// cerr << nl;
		
		// contained[idx] = distance(lower_bound(all(max_rs), r), max_rs.end());
		// contained[idx] = max_rs.size() - distance(max_rs.begin(), max_rs.lower_bound(r));
		auto lb = lower_bound(all(max_rs), r);
		contained[idx] = max_rs.end() - lb;

		max_rs.emplace(lb, r);
	}

	for(ll i = n-1; i >= 0; i--) {
		ll idx = sorted[i];
		ll r = ints[idx].second;

		// cerr << idx << ";" << r << ";";
		// for(auto i : min_rs) cerr << i << ",";
		// cerr << ";" << distance(min_rs.begin(), upper_bound(all(min_rs), r));
		// cerr << nl;
		
		// contains[idx] = distance(min_rs.begin(), upper_bound(all(min_rs), r));
		// contains[idx] = distance(min_rs.begin(), min_rs.upper_bound(r));
		auto ub = upper_bound(all(min_rs), r);
		contains[idx] = ub - min_rs.begin();

		min_rs.emplace(ub, r);
	}
	
	vout(contains, n);
	vout(contained, n);
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}