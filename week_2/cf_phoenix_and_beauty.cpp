#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        set<int> uniq;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            uniq.insert(a[i]);
        }

        if (uniq.size() > k) {
            cout << -1 << '\n';
            continue;
        }

        // Build the base beautiful segment
        vector<int> base(uniq.begin(), uniq.end());
        while ((int)base.size() < k)
            base.push_back(1);  // pad with 1

        // Build final array by repeating base
        vector<int> result;
        while ((int)result.size() < n * k)  // safe upper bound (n ≤ 100)
            for (int x : base)
                result.push_back(x);

        cout << result.size() << '\n';
        for (int x : result)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
