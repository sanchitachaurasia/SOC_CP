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
long maxpow(int a)
{
    int pow = 1;
    while (1 << pow <= a)
    {
        pow++;
    }
    return pow;
}

int main()
{
    fastio();
    int t;
    cin >> t;

    vll pow2(33);
    pow2[0] = 1;
    for (int i = 1; i <= 32; ++i)
    {
        pow2[i] = 2 * pow2[i - 1];
    }

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int c = abs(b - a);
        if (c == 0)
        {
            cout << -1 << endl;
            continue;
        }
        long long x = 0;
        ll y = 0;

        int p = max(a, b);
        int q = min(a, b);

        bitset<32> bits(c);
        bool first = true;
        int flag = 1;

        for (int i = 31; i >= 0; i--)
        {

            if (bits[i] == 1 && first)
            {
                x += pow2[maxpow(p)];

                first = false;
                y = (pow2[maxpow(p)] - pow2[i + 1]);

                flag = 0;
            }
            else if (bits[i] == 1)
            {
                if (flag == 1)
                {
                    flag = 0;
                    x += pow2[i + 1];
                }
            }
            else if (bits[i] == 0)
            {
                if (flag == 0)
                {
                    y += pow2[i + 1];
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            y++;
        }
        cout << y - q << endl;
    }
    return 0;
}