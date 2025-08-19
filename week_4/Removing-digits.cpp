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



vector<bool> ready(1e6+1,false);
vector<int> dp(1e6,0);

vector<int> digits(int n){
    vector<int> digits;
    for(int x=n;x!=0;x/=10){
        digits.pb(x%10);
    }
    return digits;
}

int countMinSteps(int n){
    ready[0]=0;
    dp[0]=0;
    if(n==0)return 0;
    for(int i=1;i<=9;++i){
        ready[i]=true;
        dp[i]=1;
        if(i==n){
        return dp[i];}
    }
    int k=INF;
    vector<int> digit=digits(n);
    for(int i=0;i<(int)digit.size();++i){
        if(digit[i]==0)continue;
        if(ready[n-digit[i]]){
            k=min(k,dp[n-digit[i]]+1);
        }
        else{
            ready[n-digit[i]]=true;
            dp[n-digit[i]]=countMinSteps(n-digit[i]);
            k=min(k,dp[n-digit[i]]+1);
        }
    }
    return k;
}

int main(){
    fastio();
    int n=1;
    cin>>n;
    cout<<countMinSteps(n)<<endl;
}
