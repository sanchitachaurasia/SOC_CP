#include <bits/stdc++.h>
using namespace std;

bool canFormRectangles(int n, vector<int>& sticks) {
    sort(sticks.begin(), sticks.end());
    vector<int> sides;

    // Form pairs of equal-length sticks
    for (int i = 0; i < 4 * n; i += 2) {
        if (sticks[i] != sticks[i + 1]) {
            return false; // can't form a side
        }
        sides.push_back(sticks[i]); // record one from each pair
    }

    int area = sides[0] * sides.back(); // area of first rectangle

    // Check each pair from front and back forms same area
    for (int i = 0; i < n; ++i) {
        if (sides[i] * sides[2 * n - 1 - i] != area)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(4 * n);
        for (int i = 0; i < 4 * n; ++i)
            cin >> a[i];

        cout << (canFormRectangles(n, a) ? "YES" : "NO") << '\n';
    }
    return 0;
}
