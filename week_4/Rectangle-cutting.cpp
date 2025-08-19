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

int main(){
    fastio();
    int a,b;
    cin>>a>>b;
    //will greedy solutionn work 
    // state: dp[i][j] represents the minm no of ways you can do the job of i*j rectangle
    //transition: if(i==j) it is 0
    //transition: dp[i][j]=dp[j][i]
    //transition: given that i>=j dp[i][j]=dp[i-j][j]+1;(greedy)
    //greedy solution wont work
    //do we need to find all and find the minm of it
    vector<vector<int>> dp(a+1,vector<int>(b+1));
    for(int i=0;i<=a;++i){
        for(int j=0;j<=b;++j){
            if(i==0||j==0){dp[i][j]=0;continue;}
            if(i==j){dp[i][j]=0;continue;}
            if(i>=j){
                dp[i][j]=dp[i-j][j]+1;
            }
            else{
                dp[i][j]=dp[i][j-i]+1;
            }
        }
    }
    cout<<dp[a][b]<<endl;
}
