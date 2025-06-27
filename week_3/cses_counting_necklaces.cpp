#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Fast exponentiation
long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long sum = 0;
    for (int k = 0; k < n; k++) {
        int g = gcd(n, k);
        sum = (sum + power(m, g)) % MOD;
    }

    long long result = sum * power(n, MOD - 2) % MOD;
    cout << result << "\n";
}
