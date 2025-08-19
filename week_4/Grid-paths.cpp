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
    int n=1;
    cin>>n;
    char A[n][n];
    for(int i=0;i<n;++i){
         for(int j=0;j<n;++j){
            cin>>A[i][j];
         }
    }
    if(A[0][0]=='*'){cout<<0<<endl;return 0;}
    if(A[n-1][n-1]=='*'){cout<<0<<endl;return 0;}
    int ans[n][n];
    ans[0][0]=0;
    bool foundx=false;
    for(int i=0;i<n;++i){
        if(A[i][0]=='*'){foundx=true;}
        if(foundx)ans[i][0]=0;
        else ans[i][0]=1;
    }
    bool foundy=false;
    for(int j=0;j<n;++j){
        if(A[0][j]=='*'){foundy=true;}
        if(foundy)ans[0][j]=0;
        else ans[0][j]=1;
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            if(A[i][j]=='*')ans[i][j]=-1;
            else {
                ans[i][j]=(max(0,ans[i-1][j])+max(0,ans[i][j-1]))%MOD;
            }
        }
    }
    cout<<ans[n-1][n-1]<<endl;
}
