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

const int N=100;
vector<int> coins(N);

int findminCoins(int x,int n,vector<int> &coins){
    vector<int> dp(x+1,INF);

    dp[0]=0;

    for(int i=1;i<=x;++i){
        for(int j=0;j<=n-1;++j){
            if(i-coins[j]>=0){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    return dp[x];
}

int main() {
    fastio();
    int n, x;
    cin >> n >> x;
    take(coins);
    int a=findminCoins(x,n,coins);
    if(a==INF)cout<<-1<<endl;
    else cout<<a<<endl;
}

