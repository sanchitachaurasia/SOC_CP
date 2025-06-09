#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
    vector<int> given(n);
    for (int &x : given) cin >> x;
 
    // Use difference array for frequency counts
    vector<int> freq_diff(n + 1, 0);
 
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        freq_diff[l] += 1;
        if (r + 1 < n) freq_diff[r + 1] -= 1;
    }
 

    vector<int> freq(n);
    freq[0] = freq_diff[0];
    for (int i = 1; i < n; ++i) {
        freq[i] = freq[i - 1] + freq_diff[i];
    }
 
    // Sort values descending
    sort(given.rbegin(), given.rend());
    // Sort frequencies descending
    sort(freq.rbegin(), freq.rend());
 
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += 1LL * given[i] * freq[i];
    }
 
    cout << ans << "\n";
 
    return 0;
}
