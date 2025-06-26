#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MOD 1000000007

const int MAX_A = 1e6 + 1;
vector<ll> fact(MAX_A);
vector<ll> inv_fact(MAX_A);

ll modpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precalculate() {
    fact[0] = 1;
    for (int i = 1; i < MAX_A; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX_A - 1] = modpow(fact[MAX_A - 1], MOD - 2);
    for (int i = MAX_A - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll binom(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

int main() {
    fastio();
    int n;
    cin >> n;
    precalculate();
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << binom(a, b) << '\n';
    }
}

