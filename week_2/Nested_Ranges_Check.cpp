#include <bits/stdc++.h>
using namespace std;

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define pb push_back
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f(i, l, n) for (decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define vin(v, n) f(i, 0, n) cin >> v[i];
#define vout(v, n)                  \
    f(i, 0, n) cout << v[i] << " "; \
    cout << nl;
#define dbg(x) cerr << #x << " = " << x << ", ";

using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using usi = unordered_set<ll>;
using si = set<ll>;
using msi = multiset<ll>;
using mi = map<ll, ll>;
using umi = unordered_map<ll, ll>;

void solve() {
    // IDEA: sort by (L, -R) so that I_i \subset I_j => i > j (sorted indices)
    // for checking contained, track max_r and check r <= max_r
    // for checking contains, track min_r and check r >= min_r (iterate reversed)

    ll n;
    cin >> n;

    vpi v(n);
    vi sorted(n);
    for (ll i = 0; i < n; i++) sorted[i] = i;

    vector<bool> contains(n, 0);
    vector<bool> contained(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    // track indices by (L, -R)
    sort(sorted.begin(), sorted.end(), [&](ll a, ll b) {
        if (v[a].first == v[b].first)
            return (v[a].second > v[b].second);
        return (v[a].first < v[b].first);
    });

    ll max_r = -1;
	for(auto i: sorted) {
		if (v[i].second <= max_r) contained[i] = 1;
		max_r = max(v[i].second, max_r);
	}

    ll min_r = 1e9+1;
	for(ll j = n-1; j >= 0; j--) {
		ll i = sorted[j];
		if (v[i].second >= min_r) contains[i] = 1;
		min_r = min(v[i].second, min_r);
	}

    vout(contains, n);
    vout(contained, n);
}

int main() {
    fastio ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}