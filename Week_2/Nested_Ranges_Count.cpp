#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<tuple<int, int, int>> ranges;
    vector<int> a(n, 0), b(n, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({l, r, i});
    }

    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    ordered_multiset right;
    for (auto [l, r, i] : ranges) {
        b[i] = right.size() - right.order_of_key(r);
        right.insert(r);
    }

    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (get<1>(a) == get<1>(b)) return get<0>(a) > get<0>(b);
        return get<1>(a) < get<1>(b);
    });

    ordered_multiset left;
    for (auto [l, r, i] : ranges) {
        a[i] = left.size() - left.order_of_key(l);
        left.insert(l);
    }

    for (int x : a) cout << x << ' ';
    cout << '\n';
    for (int x : b) cout << x << ' ';
    cout << '\n';

    return 0;
}
