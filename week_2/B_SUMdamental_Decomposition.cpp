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
	ll n, x; cin >> n >> x;

	// construction idea:
	// for n > 2, ie, there are ones and not in the first position,
	// we can always partition the powers of two, ie, subsets of the 1 positions
	// if x > 1s, just add zeros and +1 even number of times
	
	// for n = 1, the same holds except for an odd x we'll need to use
	// 2nd LSB so effective +3

	// for n = 0, the +3 is for even x

	ll ones = __builtin_popcount(x);

	if (x == 1) {
		if (n%2) {
			cout << n << nl; return;
		}
		else {
			cout << n+3 << nl; return;
		}
	}

	if (x == 0) {
		if (n == 1) {
			cout << "-1\n"; return;
		}
		if (n%2) {
			cout << n+3 << nl; return;
		}
		else {
			cout << n << nl; return;
		}
	}

	if (n >= ones && x >= 2) {
		ll extra = (n - ones);

		if (extra % 2) extra++;

		ll ans = x + extra;

		cout << ans << nl;
		return;
	}

	cout << x << nl; return;
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}