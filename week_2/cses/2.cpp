#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int,int,int>> ranges(n);
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
    multiset<int> rights;

    for (int i = n - 1; i >= 0; --i) {
        int r = get<1>(ranges[i]);
        if (!rights.empty() && *rights.begin() <= r)
            contains[get<2>(ranges[i])] = 1;
        rights.insert(r);
    }

    rights.clear();

    for (int i = 0; i < n; ++i) {
        int r = get<1>(ranges[i]);
        if (!rights.empty() && *rights.rbegin() >= r)
            contained[get<2>(ranges[i])] = 1;
        rights.insert(r);
    }

    for (int x : contains) cout << x << ' ';
    cout << '\n';
    for (int x : contained) cout << x << ' ';
}
