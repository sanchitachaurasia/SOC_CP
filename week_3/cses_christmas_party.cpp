#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> der(n + 1);
    der[0] = 1;  // By definition
    if (n >= 1) der[1] = 0;
    if (n >= 2) der[2] = 1;

    for (int i = 3; i <= n; i++) {
        der[i] = (i - 1) * (der[i - 1] + der[i - 2]) % MOD;
    }

    cout << der[n] << "\n";
    return 0;
}
