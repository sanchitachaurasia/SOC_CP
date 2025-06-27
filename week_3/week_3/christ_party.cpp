#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int main() {
    int n;
    cin >> n;

    vector<ll> derange(n + 2);
    derange[0] = 1; // by convention
    derange[1] = 0;

    for (int i = 2; i <= n; ++i) {
        derange[i] = (i - 1) * (derange[i - 1] + derange[i - 2]) % MOD;
    }

    cout << derange[n] << '\n';
    return 0;
}
