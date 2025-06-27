#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5; // Need to handle up to n+m

vector<long long> fact(MAX), inv_fact(MAX);

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

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    precompute();
    cout << nCr(n + m - 1, m) << "\n";
}
