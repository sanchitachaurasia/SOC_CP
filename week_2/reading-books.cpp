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
#define in(a) for (auto &x : a)
 
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
 
int main() {
    fastio();
    int n;
    cin>>n;
    ll k=0;
    ll sum=0;
    vll given(n);
    in(given){cin>>x;k=chmax(k,x);sum+=x;}
    cout<<chmax(sum,2*k)<<endl;
    return 0;
}
