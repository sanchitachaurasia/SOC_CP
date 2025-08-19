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


//trying to create a dp
//let there be sum 
// dp state is dp[i][j](total number of pages) where i is thne number of the books from the strating and j is the max cost



int main(){
    fastio();
    int n,x;
    cin>>n>>x;
    vector<int> price(n);
    take(price);
    vector<int> pages(n);
    take(pages);

    vector<int> newDp(x+1);
    newDp[0]=0;
    for(int j=0;j<n;++j){
        for(int i=x;i>=price[j];--i){
            newDp[i]=max(newDp[i],newDp[i-price[j]]+pages[j]);
        }
    }
    cout<<newDp[x]<<endl;

}
