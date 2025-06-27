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

const int divider = 998244353;

ll modpow(ll a, ll b, ll m)
{
    a %= m;
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

void reduce(ll &x, ll &y)
{
    ll g = __gcd(x, y);
    x /= g;
    y /= g;
}


void addwithfraction(ll &a, ll &b, ll c, ll d)
{
    a = a * d + b * c;
    b = b * d;
}
ll modinv(ll a) {
    return modpow(a, divider - 2, divider);
}

int main() {
    fastio();
    int n;
    cin >> n;
    vector<int> k(n);
    map<int, int> giftcollection;
    vector<vector<int>> giftsforeach(n);

    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        vector<int> gifts(k[i]);
        for (int j = 0; j < k[i]; ++j) {
            cin >> gifts[j];
            giftcollection[gifts[j]]++;
        }
        giftsforeach[i] = gifts;
    }

    ll inv_n = modinv(n);
    ll inv_n2 = (inv_n * inv_n) % divider;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll inv_ki = modinv(k[i]);
        for (int j = 0; j < k[i]; ++j) {
            int item = giftsforeach[i][j];
            ll term = giftcollection[item];
            term = (term * inv_ki) % divider;
            term = (term * inv_n2) % divider;
            ans = (ans + term) % divider;
        }
    }
    cout << ans << endl;
}

