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
	int t, n; cin >> n;

	// store all stick lengths: count
	unordered_map<int, int> sticks_cnts;

	for(int i = 0; i < 4 * n; i++) {
		cin >> t;
		sticks_cnts[t]++;
	}

	// prepare sorted list of all stick lengths with half as much occurences
	// necessary condn is that a_i * a_{2n-1-i} be constant
	vector<int> sticks(2 * n);

	int k = 0;
	for(auto [len, cnt] : sticks_cnts) {
		if (cnt % 2) {
			cout << "NO\n"; return;
		}
		while(cnt -= 2, cnt >= 0) {
			sticks[k] = len;
			k++;
		}

	}

	sort(all(sticks));

	int prod = sticks[0] * sticks[2 * n - 1];

	for(int i = 1; i < n; i++) {
		if (sticks[i] * sticks[2 * n - 1 - i] != prod) {
			cout << "NO\n"; return;
		}
	}

	cout << "YES\n";
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}