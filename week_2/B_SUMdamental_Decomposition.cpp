#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vec_cin(v,n) f(i,0,n) cin >> v[i];
#define vec_cout(v,n) f(i,0,n) cout << v[i] << " "; cout<<endl;
#define dbg(x) cerr << (#x) << " = " << (x) << ", ";

using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll,ll>;
using vpi = vector<pi>;
using usi = unordered_set<ll>;
using si = set<ll>;
using msi = multiset<ll>;
using mi = map<ll,ll>;
using umi = unordered_map<ll,ll>;

ll f(vi v) {
	ll n = 0;
	for (auto i : v) n ^= i;
	return n;
}

void solve() {
	ll n, x; cin >> n >> x;
	ll res = n;
	vi v(n, 1);
	ll k = (n & 1);

	// cerr << endl; dbg(n); dbg(x); cerr << endl;

	ll p = 1;
	for(int i = 0; i < 32; i++) {
		// dbg(k); dbg(p); dbg(res); dbg(x&p); dbg(k&p); cerr << endl;
		// if i-th bit in x and res dont match, add 2^i
		if ((x&p) != (k&p)) {
			// cerr << "! ";
			res += (p);
			auto min_it = min_element(all(v));
			ll old = (*min_it);
			(*min_it) += p;
			k ^= (*min_it) ^ (old);
		}
		// early break
		if (k == x) break;
		p <<= 1;
	}

	if (k != x) {
		cout << "-1\n"; return;
	}

	// can remove unnecessary 1's
	ll rem = 0;
	for(auto i: v) if ((i>1) && (i&1)) rem++;

	res -= (rem/2) * 2;

	cout << res << '\n';
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}