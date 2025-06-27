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
#define rep(x, i) for (int i = 0; i < (x); ++i)
#define in(x) for (auto &i : x)
#define chmin(a, b) (a = min((a), (b)))
#define chmax(a, b) (a = max((a), (b)))
#define vsort(v) sort(all(v))
#define print(x)          \
    for (auto i : x)      \
        cout << i << " "; \
    cout << endl;
#define take(x)                 \
    for (int i = 0; i < n; ++i) \
        cin >> x[i];
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endlc '\n'
#define lb lower_bound
#define ub upper_bound
#define uniq(v) v.erase(unique(all(v)), v.end())

const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
ll fact[21] = {};

void calc()
{
    fact[0] = 1;
    rep(20, i)
    {
        fact[i + 1] = (i + 1) * fact[i];
    }
    return;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    calc();
    while (t--)
    {
        ll x;
        cin >> x;
        ll n;
        cin >> n;
        vll base;
        rep(n, i)
        {
            base.push_back(i + 1);
        }

        if (x == 1)
        {
            ll num;

            cin >> num;
            num--;
            vll perm;
            int k = n - 1;
            while (k >= 0)
            {
                int jj = num / fact[k];
                perm.push_back(base[jj]);
                num = num - jj * fact[k];
             
                base.erase(base.begin() + jj);

                k--;
            }
            print(perm)
        }
        if (x == 2)
        {
            ll posi = 1;

            vll perm;
            rep(n, i)
            {
                ll kk;
                cin >> kk;
                perm.push_back(kk);
            }
            for (int i = 0; i < n; i++)
            {
                rep(n, k)
                {
                    if (perm[i] == base[k])
                    {
                        posi += (fact[n - 1 - i] * k);
                        base.erase(base.begin() + k);
                        break;
                    }
                }
            }
            cout << posi << endl;
        }
    }
    return 0;
}