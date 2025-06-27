#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> freq(n + 2, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;
        freq[l - 1]++;
        freq[r]--;
    }

    vector<int> cnt(n);
    cnt[0] = freq[0];
    for (int i = 1; i < n; ++i)
        cnt[i] = cnt[i - 1] + freq[i];

    sort(a.begin(), a.end());
    sort(cnt.begin(), cnt.end());

    ll res = 0;
    for (int i = 0; i < n; ++i)
        res += 1LL * a[i] * cnt[i];

    cout << res << '\n';
}
