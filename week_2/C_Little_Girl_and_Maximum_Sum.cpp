#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff(i, l, n) for(decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define vin(v,n) ff(i,0,n) cin >> v[i];
#define vout(v,n) ff(i,0,n) cout << v[i] << " "; cout<<nl;
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

#define F first
#define S second

void solve() {
	ll n, q, l, r;
	cin >> n >> q;

	// greedy algo:
	// count how many times each index occurs in b
	// sort a and b and multiply pointwise to maximize sum
	// complexity is nlogn + nq ~ n^2 too much

	// store queries as list of pairs
	// we need for each k = 1..n, how many intervals cover k
	// do this by incr l_i and decr r_i+1 for all queries
	// and taking the k-th prefix sum gives you #intervals covering it

	vi a(n);
	vi occurrences(n, 0);
	vi covers(n, 0);
	// vpi qs(q);

	vin(a, n);

	for(ll i = 0; i<q; i++) {
		// cin >> qs[i].F >> qs[i].S;
		ll l, r;
		cin >> l >> r;
		covers[l-1]++;
		if (r < n) covers[r]--;
	}

	// sort(qs.begin(), qs.end());
	// sort by (L, R)
	// so that search can go linearly

	// for(auto [a, b]:qs) cerr << a << "," << b << " ";
	// cerr << nl;


	// unsigned ll i = 0;
	// for (unsigned x = 1; x <= n; x++)
	// {
	// 	for(unsigned ll k = i; k < q; k++) {
	// 		if (qs[k].F <= x && x <= qs[k].S) {
	// 			i = k;
	// 			while(k < q && qs[k].F <= x && x <= qs[k].S) k++;
	// 			occurrences[x-1] = k - i;
	// 			break;
	// 		}
	// 	}
	// }

	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		sum += covers[i];
		occurrences[i] = sum;
	}

	sort(a.begin(), a.end());
	sort(occurrences.begin(), occurrences.end());

	
	
	ll res = 0;
	for(ll i = 0; i < n; i++) res += a[i] * occurrences[i];


	cout << res;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}