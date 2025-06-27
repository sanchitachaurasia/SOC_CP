#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> t(n);
    long long total = 0, mx = 0;

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        total += t[i];
        mx = max(mx, t[i]);
    }

    cout << max(total, 2 * mx) << '\n';
}
