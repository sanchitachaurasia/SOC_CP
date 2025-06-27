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

#define ull unsigned ll

void solve() {
	ull x, y; cin >> x >> y;
	if (x < y) swap(x, y);

	// idea:
	// we need k such that x+k and y+k have set bits at exclusive positions
	// one trick is to think in terms of subtractions:
	// x > y, then we can subtract y both sides and k = -y works!
	// another nice way to apply this is:
	//     k = x % (highest power of 2 in x say n)
	//     so k+x = 2^(n+1)
	//     y < x implies, k+y < 2^(n+1) hence set bits must be different
	//     so use ~x+1 to get negation and apply a mask
	// only other case is x = y which is IMPOSSIBLE

	if (x == y)  {
		cout << "-1\n"; return;
	}

	ull mask = 2;
	ull t = x;
	while(t >>= 1) mask <<= 1;

	mask -= 1;

	ull k = (~x + 1) & mask;

	assert((x+k) + (y+k) == (x+k) ^ (y+k));

	cout << k << "\n";
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}