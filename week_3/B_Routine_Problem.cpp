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

int gcd(int a, int b) {
	int tmp;
	if (a < b) swap(a, b);
	while(b > 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

void solve() {
	int a, b, c, d, p, q; cin >> a >> b >> c >> d;

	// ratio = horizontal : vertical = horizontal length if vertical=1
	
	// if screen ratio > picture ratio
	// a vertical gap is left
	// with width = a - bc/d = (ad-bc)/d
	// and ratio = (ad - bc) / (ad)
	if (a * d > b * c) {
		p = a*d - b *c;
		q = a*d;
	}
	else if (a * d < b * c) {
		p = b*c - a*d;
		q = b*c;
	}
	else {
		cout << "0/1";
		return;
	}

	int g = gcd(p, q);
	p /= g; q /= g;

	cout << p << "/" << q;

}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}