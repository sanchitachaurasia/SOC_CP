#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;

    if (x == y) {
        cout << -1 << "\n";
    } else {
        long long limit = 281474976710656LL;
        cout << limit - max(x, y) << "\n";
    }
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
