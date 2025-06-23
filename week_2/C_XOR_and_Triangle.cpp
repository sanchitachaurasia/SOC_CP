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
	ll x; cin >> x;

	// idea:
	// treat each number as a set containing some subset of {1, 2, 4 ..}
	// x XOR y = A symdiff B
	// so we need A symdiff B strict subset of A U B
	// and A + A symdiff B, B + A symdiff B > A U B 

	// essentially, we need a y that is same in atleast one position and differs in atleast one
	// this is not psosible is x is 2^k or 2^k-1
	// otherwise we pick last set bit (leave it as is), set the last unset bit
	// and there is a desired y

	if (__builtin_popcount(x) == 1 || __builtin_popcount(x+1) == 1) {
		cout << "-1\n"; return;
	}
	else {
		// (x & -x) unsets all but last set bit
		// ((~x) & -(~x)) sets only last unset bit
		cout << (x & -x) + ((~x) & -(~x)) << nl; return;
	}
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}