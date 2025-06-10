#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    vector<long long> a(size);
    for (int i = 0; i < size; ++i)
        cin >> a[i];

    sort(a.rbegin(), a.rend()); // sort descending

    long long result = 0;
    int count = 1;
    for (int i = 0; i < size; ) {
        for (int j = 0; j < count && i < size; ++j, ++i) {
            result += a[i];
        }
        count *= 4;
    }

    cout << result << '\n';
    return 0;
}
