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

const ll M = 1e9+7;

ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    ll power = a;

    a %= m;
    b %= (m-1); // assuming prime m and gcd(a,m)=1

    while(b) {
        if (b&1) {res = res * power % m;}
        power = (power * power) % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    // idea:
    // treat as directed graph i->p[i] where we need to find length
    // of each disjoint cycle A_i and answer is LCM(A_1,...,A_k)
    // all lens can be found using DFS like method in O(n) time
    
    // OPTIMIZATION: was using a `seen` hashset earlier but its better
    // to store boolean index `visited`
    
    // OPTIMIZATION:
    // to compute lcm of whole array, we precompute primes upto
    // sqrt(max_len) and then take greatest exp of each prime over all len
    // then reduce them, discard duplicates, and multiply by the remaining

    // alternative is to iteratively use lcm = a*b/gcd property but
    // DOES NOT HOLD FOR MODULO M

    ll n;
    cin >> n;
    vi p(n);
    vin(p, n);
    // 0 indexed
    for (ll i = 0; i < n; i++) p[i]--;

    vi cycles;
    ll maxlen = 0;

    for (ll i = 0; i < n; i++) {
        if (p[i] == -1) continue;

        vector<bool> visited(n, 0);
        ll cnt = 0;
        ll j = i;
        while(!visited[j]) {
            visited[j] = 1;
            ++cnt;
            ll t = p[j];
            p[j] = -1; // do not go through it again
            j = t;
        }

        cycles.pb(cnt);
        maxlen = max(maxlen, cnt);
    }

    sort(all(cycles));
    cycles.resize(unique(all(cycles)) - cycles.begin());

    // for(auto x :cycles) cerr << x << " ";
    // cerr << nl;

    vi primes;
    vector<bool> sieve(maxlen+1);

    for(ll i = 2; i*i <= sieve.size(); i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            for(ll j = i*i; j<sieve.size(); j+=i) {
                sieve[i] = 1;
            }
        }
    }
    
    // for(auto x: primes) cerr << x << " ";
    // cerr << nl;

    vi exps(primes.size());
    for(ll i = 0; i<primes.size(); i++) {
        ll p = primes[i];
        ll maxexp = 0;
        for(ll& c : cycles) {
            ll exp = 0;
            while(c % p == 0) {
                c /= p;
                exp++;
            }
            maxexp = max(maxexp, exp);
        }
        exps[i] = maxexp;
    }

    sort(all(cycles));
    cycles.resize(unique(all(cycles)) - cycles.begin());
    // for(auto x: cycles) cerr << x << " ";
    // cerr << nl;

    ll lcm = 1;
    for(ll i = 0; i<primes.size(); i++) {
        lcm = (lcm * modpow(primes[i], exps[i], M)) % M;
    }

    for(auto c : cycles) {
        lcm = (lcm * c) % M;
    }

    cout << lcm << nl;
}

int main() {
    fastio ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}