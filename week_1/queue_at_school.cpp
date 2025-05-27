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
	// read as bitarray B - 1 G - 0
	vector<bool> a;
	int n, x;
	char c;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		a.pb(c == 'B' ? 1 : 0);
	}

	bool prev = a[n-1];
	int consec = 0;  // number of consec ones to the right
	int added = 0; // number of ones already appended

	for (int i = n - 2; i > 0; i--) {
		if (a[i] && prev) consec++;
		// else if ()
		
		if (a[i]) {
			swap(a[i], a[max(i+x, n-1-added)]);
			added++;
		}

		prev = a[i];
	}
	
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}