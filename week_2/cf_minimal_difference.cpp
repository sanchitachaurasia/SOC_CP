#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        // Map to store the last occurrence index of each number
        unordered_map<int, int> last_seen;
        int min_len = n + 1;

        for (int i = 0; i < n; ++i) {
            if (last_seen.count(a[i])) {
                min_len = min(min_len, i - last_seen[a[i]] + 1);
            }
            last_seen[a[i]] = i;
        }

        if (min_len == n + 1)
            cout << -1 << '\n';
        else
            cout << min_len << '\n';
    }

    return 0;
}
