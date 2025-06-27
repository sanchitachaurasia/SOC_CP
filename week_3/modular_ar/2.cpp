#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 998244353;
const int MAX = 1000005;

// Function to compute (base^exp) % mod
long long mod_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// Function to compute modular inverse
long long mod_inv(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> kid_items(n);
    vector<int> item_count(MAX, 0); // how many kids want each item

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        kid_items[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> kid_items[i][j];
            item_count[kid_items[i][j]]++;
        }
    }

    long long numerator = 0;
    for (int i = 0; i < n; ++i) {
        long long k_size = kid_items[i].size();
        long long inv_k = mod_inv(k_size, MOD);
        for (int item : kid_items[i]) {
            numerator = (numerator + item_count[item] * inv_k % MOD) % MOD;
        }
    }

    // Now divide numerator by n*n
    numerator = numerator * mod_inv(n, MOD) % MOD;
    numerator = numerator * mod_inv(n, MOD) % MOD;

    cout << numerator << '\n';
    return 0;
}
