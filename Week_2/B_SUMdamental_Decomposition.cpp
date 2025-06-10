#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
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

const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int x = __builtin_popcount(k);
        int sum;
        if (x >= n)
        {
            sum = k;
        }
        else
        {
            int t = n - x;
            
            if (t % 2 == 1 && k > 1)
            {
                sum = k + t+1;
            }
            else if(k==0){
                if(n==1){sum=-1;}
                else if(n%2==1){
                    sum=n+3;
                }
                else{sum=n;}
            }
            else if (k == 1 && n % 2 == 0)
            {
                sum = n + 3;
            }
            else if (k == 1 && n % 2 == 1)
            {
                sum = n;
            }
            else
                sum = k + t;
        }
        cout << sum << "\n";
    }
    return 0;
}