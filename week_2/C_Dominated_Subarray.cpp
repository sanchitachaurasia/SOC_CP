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

	unordered_map<ll, vi> idx_map;

	// greedy algo: smallest substring w two occurences of an item works
	// bcz if it doesnt, there must be a smaller one contained in it
	// which has two occurence of an item (contradicts the minimality)
	// or >2 occurence (again contradiction)

	// map num -> array of all indices it occurs at
	for(ll i = 0; i<n; i++) {
		if (!idx_map.count(a[i])) { idx_map[a[i]] = {i}; }
		else {
			idx_map[a[i]].push_back(i);
		}
	}

	ll res = 2e5 + 2;

	for(auto &[num, idxs] : idx_map) {
		if (idxs.size() < 2) continue;
		// find min difference bw any two elements
		// sort and iterate w one pointer
		sort(all(idxs));

		for(ll i = 0; i < idxs.size() - 1; i++) {
			res = min(res, idxs[i+1] - idxs[i] + 1);
		}
	}

	if (res == 2e5+2) res = -1;

	cout << res << nl;
}

void _solve() {
	ll n; cin >> n;
	vi a(n);

	vin(a, n);

	ll curr = -1;
	ll res = 2e5 + 1;
	bool found = false;

	for(ll i = 0; i < n - 1; i++) {
		curr = a[i];
		for(ll j = i + 1; j < n; j++) {
			if (a[j] == curr) {
				found = true;
				res = min(res, j - i + 1);
				break;
			}
		}
	}
	cout << (found ? res : -1) << nl;
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}