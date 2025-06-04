#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> books(n);
    long long total = 0, max_time = 0;

    for (int i = 0; i < n; ++i) {
        cin >> books[i];
        total += books[i];
        max_time = max(max_time, (long long)books[i]);
    }

    cout << max(total, 2 * max_time) << "\n";
    return 0;
}
