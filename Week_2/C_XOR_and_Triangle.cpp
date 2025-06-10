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
    unordered_map<int, int> exclude;
    rep(31)
    {
        exclude[pow(2, i)] = 1;
    }
    while (t--)
    {
        int n;
        cin >> n;
        if (exclude[n] == 1 || exclude[n + 1] == 1)
        {
            cout << "-1" << "\n";
            continue;
        }
        int num = 1;
        while (2 * num < n)
        {
            num *= 2;
        }
        cout << num - 1 << "\n";
    }
    return 0;
}