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
	vi a(n);
	vin(a, n);

	unordered_set<ll> old_seg, curr_seg;
	ll start = 0, stop = 0;  // start is begin, stop is beyond end
	ll res = 1;

	// initialize
	for(ll i = 0; i<n; i++) {
		if (old_seg.count(a[i])) {
			break;
		}
		old_seg.insert(a[i]); stop++;
	}

	if (stop == n) {
		cout << "1\n";
	}

	start = stop;

	for(ll i = start; i<n; i++) {
		old_seg.erase(a[i]);
		curr_seg.insert(a[i]);
		if (old_seg.empty()) {
			// found new segment
			res++;
			old_seg = curr_seg;
			curr_seg.clear();
		}

		cerr << i << " ";
		cerr << "{ ";
		for(auto i: old_seg) cerr << i << " ";
		cerr << "}\t";
		
		cerr << "{ ";
		for(auto i: curr_seg) cerr << i << " ";
		cerr << "}\n";
	}

	cout << res << nl;
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}