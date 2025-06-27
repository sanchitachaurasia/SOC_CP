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
	vi t(n);
	vin(t, n);

	ll res = 0;

	sort(rall(t));

	ll tot = 0;
	for(auto i : t) tot += i;

	// greedy algo:
	// K reads the longest book and in that time the other reads
	// anything but that
	// if the longest book (T) is long enough to contain all others, we return 2*T
	// otherwise we can schedule some book that T has already read
	// if there is no such book, that contradicts T's maximality
	// now we can adjust any remaining books in a way that prevents overlaps
	// and overall we get the sum as the answer

	if (tot <= 2 * t[0]) {
		cout << 2 * t[0];
	} else {
		cout << tot;
	}
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}