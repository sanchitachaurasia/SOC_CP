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
	ll n; cin >> n;
	vi a(n);

	vin(a, n);

	// greedy idea:
	// track the array max upto index i
	// for all indices i, count the difference as a[i]-curr_max
	// this is the value we need to compensate for
	// since we can choose indices freely, all we need is posn of last set bit in max difference

	ll curr_max = a[0];
	ll max_diff = 0;

	for (ll i = 1; i < n; i++)
	{
		if (a[i] >= curr_max) {
			curr_max = a[i];
		}
		else {
			max_diff = max(max_diff, curr_max - a[i]);
		}
	}

	ll pow2 = 1;

	if (max_diff == 0) {cout << "0\n"; return; }

	assert(max_diff > 0);

	while(max_diff >>= 1) {
		pow2++;
	}
	
	cout << pow2 << nl;
	
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}