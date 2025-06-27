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
#define ff(i, l, n) \
    for (decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define vin(v, n) ff(i, 0, n) cin >> v[i];
#define vout(v, n)                   \
    ff(i, 0, n) cout << v[i] << " "; \
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

void fwd_pass(int val, string& s, vi& cnts) {
    ll n = s.size();
    for (ll i = 0; i < n; i++) {
        ll x = s[i] - '0';
        if (x > val && cnts[val] < n / 3 && cnts[x] > n / 3) {
            s[i] = '0' + val;
            cnts[val]++;
            cnts[x]--;
        }
    }
}

void bkwd_pass(int val, string& s, vi& cnts) {
    ll n = s.size();

    for (ll i = n - 1; i >= 0; i--) {
        ll x = s[i] - '0';
        if (x < val && cnts[val] < n / 3 && cnts[x] > n / 3) {
            s[i] = '0' + val;
            cnts[val]++;
            cnts[x]--;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    string s;
    s.resize(n);

    vi cnts(3, 0);
    char c;
    for (ll i = 0; i < n; i++) {
        cin >> c;
        cnts[c - '0']++;
        s[i] = c;
    }

    // greedy algo:
    // to create min altered balanced string
    // we have to minimize the differences from n/3 to zero
    // now the following greedy strat works for LEXICO MIN
    // for a given char to add more of,
    // if s[i] has larger value, then start replacing it from front (as long as required and feasible)
    // if s[i] has smaller value, then start replacing it from back (as long as required and feasible)

    fwd_pass(0, s, cnts);
    fwd_pass(1, s, cnts);
    bkwd_pass(2, s, cnts);
    bkwd_pass(1, s, cnts);

    cout << s;
}

int main() {
    fastio ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}