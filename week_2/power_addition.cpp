#include <bits/stdc++.h>
using namespace std;

int highestSetBitPos(long long x) {
    int pos = 0;
    while (x > 0) {
        pos++;
        x >>= 1;
    }
    return pos;
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long maxDiff = 0;
        b[0] = a[0];
        for (int i = 1; i < n; i++) {
            b[i] = max(b[i-1], a[i]);
        }

        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, b[i] - a[i]);
        }

        if (maxDiff == 0) {
            cout << 0 << "\n";
        } else {
            cout << highestSetBitPos(maxDiff) << "\n";
        }
    }

    return 0;
}
