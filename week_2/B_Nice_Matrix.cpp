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
#define vout(v,n) f(i,0,n) cerr << v[i] << " "; cerr<<nl;
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

ll c(vi& arr) {
	// return cost for an array of linked elements
	// cost = min sum |k - x_i| over all k, and occurs for k = median
	// equals the last half sum minus first half sum
	if (arr.size() == 4) {
		sort(all(arr));
		return arr[3] + arr[2] - arr[1] - arr[0];
	}
	if (arr.size() == 2) return abs(arr[1] - arr[0]);
	return 0;
}

void solve() {
	int n, m; cin >> n >> m;

	vector<vector<ll>> a(n, vector<ll>(m));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}


	int mid_row = (n % 2 ? n/2 : -1);
	int mid_col = (m % 2 ? m/2 : -1);

	ll cost = 0;

	for(int i = 0; i < (n+1)/2; i++) {
		for(int j = 0; j < (m+1)/2; j++) {
			if (i == mid_row && j == mid_col) {
				// nothing
			}
			else if (i == mid_row) {
				vi arr = {a[i][j], a[i][m-1-j]};
				cost += c(arr);
			}
			else if (j == mid_col) {
				vi arr = {a[i][j], a[n-1-i][j]};
				cost += c(arr);
			}
			else {
				vi arr = {a[i][j], a[n-1-i][j], a[n-1-i][m-1-j], a[i][m-1-j]};
				cost += c(arr);
			}
		}
	}

	cout << cost << nl;
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}