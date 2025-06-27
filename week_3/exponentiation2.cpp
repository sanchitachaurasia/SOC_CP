#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Type aliases
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>

// Shortcuts
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

// Loops
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define in(x) for (auto &i : x)

// Math utilities
#define chmin(a, b) (a = min((a), (b)))
#define chmax(a, b) (a = max((a), (b)))
#define vsort(v) sort(all(v))

// Constants
const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// Debug (disable on online judges)
#ifndef ONLINE_JUDGE
  #define debug(x) cerr << #x << " = "; _print(x); cerr << '\n';
  template<class T> void _print(T x) { cerr << x; }
  template<class T> void _print(vector<T> v) { cerr << "["; for (T i : v) cerr << i << " "; cerr << "]"; }
#else
  #define debug(x)
#endif

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll secbinpow(ll a,ll b,ll c){
    return binpow(a,binpow(b,c,MOD-1),MOD);
}

int main() {
    fastio();
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<secbinpow(a,b,c)<<endl;
    }
    return 0;
}
