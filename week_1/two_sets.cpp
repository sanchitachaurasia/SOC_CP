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
	int n;
	cin >> n;

	if (n % 4 == 1 or n % 4 == 2) {
		cout << "NO";
		return;
	}

	cout << "YES\n";

	if (n % 4 == 0) {
		cout << n / 2 << endl;
		for (int i = 1; i <= n / 4; i++)
		{
			cout << i << " " << n + 1 - i << " ";
		}
		cout << endl;
		
		cout << n / 2 << endl;
		for (int i = n / 4 + 1; i <= n / 2; i++)
		{
			cout << i << " " << n + 1 - i << " ";
		}
	}

	if (n % 4 == 3) {
		n++;
		cout << n / 2 << endl;
		// treat same as above case with n removed
		// and n/2 swapped
		cout << 1 << " ";
		for (int i = 2; i <= n / 4; i++)
		{
			cout << i << " " << n + 1 - i << " ";
		}
		cout << n/2 << endl;

		cout << n/2 - 1 << endl;
		for (int i = n / 4 + 1; i < n / 2; i++)
		{
			cout << i << " " << n + 1 - i << " ";
		}
		cout << n/2 + 1 << endl;
	}
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}