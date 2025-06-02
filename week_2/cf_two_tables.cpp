#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(2 * n);
    vector<pair<int, int>> pos(n + 1); // positions of each size from 1 to n
    vector<int> cnt(n + 1, 0); // to store first and second occurrence

    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        if (cnt[a[i]] == 0) {
            pos[a[i]].first = i;
            cnt[a[i]]++;
        } else {
            pos[a[i]].second = i;
        }
    }

    int s_pos = 0, d_pos = 0;
    long long total_dist = 0;

    for (int i = 1; i <= n; ++i) {
        int p1 = pos[i].first;
        int p2 = pos[i].second;

        // Try both options and pick the one with less total distance
        int option1 = abs(s_pos - p1) + abs(d_pos - p2);
        int option2 = abs(s_pos - p2) + abs(d_pos - p1);

        if (option1 <= option2) {
            total_dist += option1;
            s_pos = p1;
            d_pos = p2;
        } else {
            total_dist += option2;
            s_pos = p2;
            d_pos = p1;
        }
    }

    cout << total_dist << '\n';
    return 0;
}
