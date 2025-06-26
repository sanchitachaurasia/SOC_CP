#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(x) for (int i = 0; i < (x); ++i)
#define in(x) for (auto &i : x)
#define chmin(a, b) (a = min((a), (b)))
#define chmax(a, b) (a = max((a), (b)))
#define vsort(v) sort(all(v))
#define print(x) for (auto i : x) cout << i << " "; cout << endl;
#define take(x) for (int i = 0; i < n; ++i) cin >> x[i];
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endlc '\n'
#define lb lower_bound
#define ub upper_bound
#define uniq(v) v.erase(unique(all(v)), v.end())
const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

const int VALMAX = 1e7;

int mobius[VALMAX];

int main() {
	int test_num;
	cin >> test_num;

	mobius[1] = -1;
	for (int i = 1; i < VALMAX; i++) {
		if (mobius[i]) {
			mobius[i] = -mobius[i];
			for (int j = 2 * i; j < VALMAX; j += i) { mobius[j] += mobius[i]; }
		}
	}

	for (int t = 0; t < test_num; t++) {
		long long n;
		long long ans = 0;
		cin >> n;
		for (int i = 1; 1LL * i * i <= n; i++) {
			ans += mobius[i] * n / ((long long)i * i);
		}
		cout << ans << '\n';
	}
}
