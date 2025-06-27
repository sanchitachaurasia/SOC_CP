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
	n %= 4;

	switch (n)
	{
	case 0:
		cout << "6\n"; return;
	case 1:
		cout << "8\n"; return;
	case 2:
		cout << "4\n"; return;
	case 3:
		cout << "2\n"; return;
	
	default:
		break;
	}
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}