#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f(i, l, n) for(decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define ll long long
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vec_cin(v,n) f(i,0,n) cin >> v[i];
#define vec_cout(v,n) f(i,0,n) cout << v[i] << " "; cout<<endl;
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
	// number at (1, 2n-1) is (2n-1)^2 and dec by 1 as row inc upto 2n-1 
	// at (1, 2n) is (2n-1)^2 + 1 and inc by as row inc upto 2n
	// otherwise, start at (2n-1/2n, 1) and then inc/dec
	ll x, y, ans;
	cin >> y >> x;
	if (x > y)
		ans = (x % 2) ? (x*x + 1 - y) : ((x-1)*(x-1) + y);
	else
		ans = (y % 2) ? ((y-1)*(y-1) + x) : (y*y + 1 - x);

	cout << ans << endl;
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}