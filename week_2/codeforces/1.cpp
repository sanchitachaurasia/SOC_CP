#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // Store last seen index for each value
        vector<int> last_seen(n + 1, -1);
        int min_len = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int val = a[i];
            if (last_seen[val] != -1) {
                min_len = min(min_len, i - last_seen[val] + 1);
            }
            last_seen[val] = i;
        }

        cout << (min_len == INT_MAX ? -1 : min_len) << '\n';
    }
}
