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

vector<long long int> fact(21);

void computeFactorials(){
    fact[0]=1;
    for(ll i=1;i<21;++i){
        fact[i]=fact[i-1]*i;
    }
}



int main(){
    fastio();
    int t=1;
    cin>>t;
    computeFactorials();
    while(t--){
        int decider=1;
        vector<int> numnbers(20);
        for(int i=0;i<20;++i){
            numnbers[i]=i+1;
        }
        cin>>decider;
        if(decider==1){
            int n=1;
            ll k=0;
            cin>>n>>k;
            k=k-1;
            for(int i=0;i<n;++i){
                cout<<numnbers[(k/fact[n-1-i])]<<" ";
                numnbers.erase(numnbers.begin()+(k/fact[n-1-i]));
                k=k%fact[n-1-i];
            }
            cout<<endl;
        }
        if(decider==2){
            int n=1;
            cin>>n;
            int given[n]={};
            take(given);
            vector<ll> multiplier(20);
            for(int i=0;i<n;++i){
                for(int j=i+1;j<n;++j){
                    if(given[i]>given[j])multiplier[i]++;
                }
            }
            ll ans=0;
            for(int i=0;i<n;++i){
                ans+=multiplier[i]*fact[n-1-i];
            }
            ans+=1;
            cout<<ans<<endl;
        }
    }
}
