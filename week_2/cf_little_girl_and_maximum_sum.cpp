#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> freq(n + 2, 0);  // freq[i] will count how many queries include position i

    while (q--) {
        int l, r;
        cin >> l >> r;
        freq[l]++;
        freq[r + 1]--;
    }

    // Build actual frequency via prefix sum
    for (int i = 1; i <= n; ++i)
        freq[i] += freq[i - 1];

    freq.resize(n); // Trim to match size of a[]

    sort(freq.begin(), freq.end());
    sort(a.begin(), a.end());

    ll result = 0;
    for (int i = 0; i < n; ++i)
        result += 1LL * freq[i] * a[i];

    cout << result << '\n';

    return 0;
}
