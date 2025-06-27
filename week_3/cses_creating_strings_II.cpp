#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

vector<long long> fact(MAX), inv_fact(MAX);

// Fast exponentiation
long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    precompute();

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    long long res = fact[s.size()];
    for (int cnt : freq) {
        if (cnt > 0)
            res = res * inv_fact[cnt] % MOD;
    }

    cout << res << "\n";
    return 0;
}
