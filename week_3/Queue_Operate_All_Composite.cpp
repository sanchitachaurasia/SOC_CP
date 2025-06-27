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
#define forr(i, l, n) \
    for (decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define vin(v, n) forr(i, 0, n) cin >> v[i];
#define vout(v, n)                     \
    forr(i, 0, n) cout << v[i] << " "; \
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

#define yes          \
    cout << "YES\n"; \
    return
#define no          \
    cout << "NO\n"; \
    return

#define ff first
#define ss second

const ll M = 998244353;

unordered_map<ll, ll> inv;

void update(ll a, ll b, ll& a_tot, ll& b_tot, bool inverse = false) {
	if (!inverse) {
		// adding function from the back ie outer most
		a_tot = (a_tot * a) % M;
		b_tot = ((a * b_tot) % M + b) % M;
	}
	else {
		// adding function from the front ie inner most
		b_tot = ((a_tot * b) % M + b_tot + M) % M;
		a_tot = (a_tot * a) % M;
	}
}

ll modinv(ll k) {
	if (inv.count(k)) return inv[k];
	assert(k > 0);
	return (inv[k] = M - (ll)(M/k) * modinv(M%k) % M);
}

void solve() {
	// earlier was erasing fi_pairs[0] in op 1, gave TLE on large q

	// idea:
	// composition of linear fns is a linear fn
	// store only the total a and b values
	// for adding functions, straightforward computation
	// for removing functions f_l treat it as applying
	// f_l^-1 first, so add that as innermost function
	// coeffs will be (a^-1, -b*a^-1)

    ll Q;
    cin >> Q;

    vpi fi_pairs;
    ll a_tot = 1;
    ll b_tot = 0;
    // vi b_arr = {};

    ll a, b, op;
	int j = 0;

    inv[1] = 1;

    for (ll i = 0; i < Q; i++) {
        cin >> op;

        if (op == 2) {
            ll res;
            cin >> res;

			// for(auto [a,b]: fi_pairs) cerr << a << "," << b << " "; cerr << nl;
			// cerr << a_tot << "," << b_tot << nl;

            res = (a_tot * res ) % M;
			res = (res + b_tot) % M;
            cout << res << nl;
            continue;
        }
        if (op == 1) {
            a = fi_pairs[j].ff;
            b = fi_pairs[j].ss;

            update(modinv(a), (-b * modinv(a)) % M, a_tot, b_tot, true);
            // fi_pairs.erase(fi_pairs.begin());
			j++;
        }
        if (op == 0) {
            cin >> a >> b;
            fi_pairs.push_back({a, b});

            update(a, b, a_tot, b_tot);
        }
    }
}

int main() {
    fastio ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}