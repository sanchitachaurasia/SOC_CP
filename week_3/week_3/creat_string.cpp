#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

vector<ll> fact(MAX), inv_fact(MAX);

// Fast exponentiation
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

int main() {
    string s;
    cin >> s;
    int n = s.size();
    precompute();

    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;

    ll res = fact[n];
    for (int f : freq)
        res = res * inv_fact[f] % MOD;

    cout << res << '\n';
    return 0;
}
