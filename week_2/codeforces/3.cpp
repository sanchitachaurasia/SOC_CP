#include <bits/stdc++.h>
using namespace std;

bool can_form_equal_rectangles(vector<int> &a, int n) {
    sort(a.begin(), a.end());
    vector<int> pairs;

    for (int i = 0; i < 4 * n; i += 2) {
        if (a[i] != a[i + 1]) return false;
        pairs.push_back(a[i]);
    }

    int target_area = pairs[0] * pairs.back();
    for (int i = 0; i < n; ++i) {
        if (pairs[i] * pairs[2 * n - 1 - i] != target_area)
            return false;
    }
    return true;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(4 * n);
        for (int &x : a) cin >> x;
        cout << (can_form_equal_rectangles(a, n) ? "YES" : "NO") << '\n';
    }
}
