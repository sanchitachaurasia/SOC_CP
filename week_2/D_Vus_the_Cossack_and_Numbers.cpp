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
	int n; cin >> n;
	vector<double> a(n);
	for(ll i = 0; i<n; i++) {
		cin>> a[i];
	}

	double _residue = 0;

	for(auto r : a) {
		// dbg(r); dbg(floor(r)); cerr << nl;
		_residue += r - floor(r);
	}

	int residue = round(_residue);

	vector<int> ans(n);

	for(ll i = 0 ; i < n ; i++) {
		// number has non zero fract part, take ceiling as long as residue
		if (a[i] - floor(a[i]) > 1e-6 && residue) {
			ans[i] = ceil(a[i]);
			residue--;
		}
		else {
			ans[i] = floor(a[i]);
		}
	}

	for(auto i : ans) {
		cout << i << nl;
	}
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}