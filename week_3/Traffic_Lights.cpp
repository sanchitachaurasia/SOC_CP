#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------- Indexed Set (No duplicates) -----------
template <typename T>
using indexed_set = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

// ----------- Simulated Ordered Multiset with Duplicates -----------
typedef pair<int, int> pii;
using ordered_multiset = tree<
    pii,
    null_type,
    less<pii>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

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

int main()
{
    fastio();
    ll n, k;
    cin >> n >> k;
    indexed_set<ll> aa;
    aa.insert(0);
    aa.insert(n);
    ordered_multiset bb;
    int uid = 0;
    bb.insert({n, uid++});
    rep(k, i)
    {
        ll z;
        cin >> z;
        aa.insert(z);
        int idx = aa.order_of_key(z);
        ll x = *aa.find_by_order(idx - 1);
        ll y = *aa.find_by_order(idx + 1);
        bb.erase(bb.lower_bound({y - x, -1}));
        bb.insert({z - x, uid++});
        bb.insert({y - z, uid++});

        cout << bb.find_by_order(bb.size() - 1)->first << ' ';
    }

    return 0;
}