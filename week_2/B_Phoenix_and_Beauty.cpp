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

void solve() {
	ll n, k; cin >> n >> k;
	vi a(n);

	vin(a, n);

	// greedy idea:
	// for every element a[i] in original array
	// say a[j] = a[i] for j > i
	// we need j - i = k for all such pairs
	// we need an array periodic in k
	// so extract all unique elements p
	// p > k => impossible
	// p <= k => add numbers to make p=k
	// repeat these k numbers n times so every a[i] occurs atleast once in order

	si s;

	for(auto i : a) {
		s.insert(i);
	}

	if (s.size() > k) {
		cout << "-1\n"; return;
	}
	else if (s.size() < k) {
		for (ll i = 1; i <= n; i++)
		{
			s.insert(i);
			if (s.size() == k) break;
		}
	}

	cout << n * k << nl;
	for(ll i = 0; i < n; i++) {
		for(auto x : s) cout << x << " ";
	}
	cout << nl;
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}