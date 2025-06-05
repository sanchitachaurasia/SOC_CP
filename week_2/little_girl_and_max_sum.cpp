#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> val(n + 1, 0);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        val[l]++;
        if (r + 1 < n)
            val[r + 1]--;
    }

    // Prefix sum to get frequency counts
    for (int i = 1; i < n; i++)
        val[i] += val[i - 1];

    val.resize(n); // Remove extra element

    sort(val.begin(), val.end());

    long long result = 0;
    for (int i = 0; i < n; i++)
        result += (long long)val[i] * a[i];

    cout << result << "\n";

    return 0;
}
