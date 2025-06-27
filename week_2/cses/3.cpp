#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<array<int,3>> ranges(n); // {l, r, original_index}
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ranges[i] = {a, b, i};
    }

    sort(ranges.begin(), ranges.end(), [](auto &x, auto &y) {
        if (x[0] == y[0]) return x[1] > y[1];
        return x[0] < y[0];
    });

    vector<int> contains(n), contained(n);
    {
        vector<int> ends;
        for (auto &[l, r, idx] : ranges) ends.push_back(r);
        sort(ends.begin(), ends.end());
        ends.erase(unique(ends.begin(), ends.end()), ends.end());

        vector<int> bit(ends.size() + 2);

        auto update = [&](int i) {
            for (++i; i < bit.size(); i += i & -i) bit[i]++;
        };
        auto query = [&](int i) {
            int res = 0;
            for (++i; i > 0; i -= i & -i) res += bit[i];
            return res;
        };

        for (int i = n - 1; i >= 0; --i) {
            int r = ranges[i][1];
            int pos = lower_bound(ends.begin(), ends.end(), r) - ends.begin();
            contains[ranges[i][2]] = query(pos);
            update(pos);
        }
    }

    {
        vector<int> ends;
        for (auto &[l, r, idx] : ranges) ends.push_back(r);
        sort(ends.begin(), ends.end());
        ends.erase(unique(ends.begin(), ends.end()), ends.end());

        vector<int> bit(ends.size() + 2);

        auto update = [&](int i) {
            for (++i; i < bit.size(); i += i & -i) bit[i]++;
        };
        auto query = [&](int i) {
            int res = 0;
            for (++i; i > 0; i -= i & -i) res += bit[i];
            return res;
        };

        for (int i = 0; i < n; ++i) {
            int r = ranges[i][1];
            int pos = lower_bound(ends.begin(), ends.end(), r) - ends.begin();
            contained[ranges[i][2]] = i - query(pos - 1);
            update(pos);
        }
    }

    for (int x : contains) cout << x << ' ';
    cout << '\n';
    for (int x : contained) cout << x << ' ';
    cout << '\n';
}
