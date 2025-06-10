#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> ranges(n); // {x, y, original index}
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ranges[i] = {x, y, i};
    }

    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    vector<int> contains(n), contained(n);
    int max_y = -1;

    for (auto &t : ranges) {
        int x = get<0>(t);
        int y = get<1>(t);
        int idx = get<2>(t);
        if (y <= max_y)
            contained[idx] = 1;
        max_y = max(max_y, y);
    }

    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) < get<1>(b);
        return get<0>(a) > get<0>(b);
    });

    int min_y = INT_MAX;
    for (auto &t : ranges) {
        int x = get<0>(t);
        int y = get<1>(t);
        int idx = get<2>(t);
        if (y >= min_y)
            contains[idx] = 1;
        min_y = min(min_y, y);
    }

    for (int x : contains) cout << x << " ";
    cout << "\n";
    for (int x : contained) cout << x << " ";
}
