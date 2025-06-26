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

const ll MAXN = 20;
ll fact[MAXN+1];

void solve() {
    

    ll n, op;
    cin >> op >> n;

    fact[0] = 1;
    for(ll i = 1; i<=n; i++) fact[i] = i * fact[i-1];

    // set of 1..n to choose/compare from
    vi choose(n);
    iota(all(choose), 1);

    if (op == 1) {
        ll k;
        cin >> k;
		--k;

        vi a(n);
        a[n-1] = k;
        for(ll i = 1; i<n; i++) {
            a[n - 1 - i] = k / fact[i];
        }

        ll rem = n;

        for(ll i = 0; i<n; i++) {
            ll gap = (k / fact[n-1-i]) % (rem);
            // ll j = 0;
            // while(gap > 0 || !choose[j]) {
            //     if (!choose[j]) j++;
            //     else {j++; gap--;}
            //     j %= n;
            // }
            // // dbg(gap); dbg(j); dbg(choose[j]); cerr <<nl;
            // cout << choose[j] << " ";
            // choose[j] = 0;

            // dbg(gap); dbg(j); dbg(choose[j]); cerr <<nl;
            cout << choose[gap] << " ";
            choose.erase(gap + choose.begin());
            rem--;
        }
        cout << nl;
    }
    else {
        vi a(n);
        vin(a, n);

        ll k = 0;

        for(ll i = 0; i<n; i++) {
            ll jmp=0;
            ll j = 0;
            // while(!choose[j] || choose[j] < a[i]) {
            //     if (!choose[j]) j++;
            //     else {j++; jmp++;}
            //     j %= n;
            // }
            // choose[j] = 0;

            j = lower_bound(all(choose), a[i]) - choose.begin();
            jmp = j;
            choose.erase(j + choose.begin());
            
            // dbg(i); dbg(jmp); dbg(j); dbg(fact[n-1-i]); cerr <<nl;
            k += jmp * fact[n-1-i];
        }

        cout << k+1 << nl;
    }
}

int main() {
    fastio ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}