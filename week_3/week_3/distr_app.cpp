#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;

vector<ll> fact(MAX), inv_fact(MAX);

// Modular exponentiation
ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = inv_fact[0] = 1;
    for(int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2, MOD);
    for(int i = MAX - 2; i >= 1; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

// Compute C(a, b) = a! / (b! * (a - b)!) % MOD
ll comb(int a, int b) {
    if(b < 0 || b > a) return 0;
    return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

int main() {
    int n, m;
    cin >> n >> m;
    precompute();
    cout << comb(n + m - 1, m) << '\n';
    return 0;
}
