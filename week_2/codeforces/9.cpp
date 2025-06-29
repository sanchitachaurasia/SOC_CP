#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> s;
        for (int &x : a) {
            cin >> x;
            s.insert(x);
        }

        if (s.size() > k) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> base(s.begin(), s.end());
        while (base.size() < k) base.push_back(1);

        vector<int> res;
        for (int i = 0; i < n; ++i)
            for (int x : base) res.push_back(x);

        cout << res.size() << '\n';
        for (int x : res) cout << x << ' ';
        cout << '\n';
    }
}
