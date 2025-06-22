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
	// idea: sort by (L, R)
	// iterate over all guests and build min heap of allocated rooms (latest departure, room no) (sort by latest departure)
	// overall - n log n

	// 3 tuple for (L, R, idx)
	ll n; cin >> n;
	vector<tuple<ll, ll, ll>> guests(n);
	
	ll a, b;
	for(ll i = 0; i < n; i++){
		cin >> a >> b;
		guests[i] = {a, b, i};
	}

	sort(all(guests));

	// for(auto [a, b, c] : guests) cerr << a << "," << b << "," << c << " ";
	// cerr << nl;

	ll room_count = 0;
	vi ans(n);
	// (latest departure, room no)
	priority_queue<pi, vpi, greater<pi>> rooms;

	for (auto &[start, stop, idx] : guests)
	{
		// if room available update and proceed
		if (!rooms.empty() && rooms.top().first < start) {
			auto [_, room_no] = rooms.top(); rooms.pop();
			ans[idx] = room_no;
			rooms.push({stop, room_no});
		}
		// else add a room and push it to Q
		else {
			room_count++;
			rooms.push({stop, room_count});
			ans[idx] = room_count;
		}
	}

	cout << room_count << nl;
	for(auto i : ans) cout << i << " ";
	cout << nl;
	
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}