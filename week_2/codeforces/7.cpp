#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    vector<long long> a(size);
    for (auto &x : a) cin >> x;

    sort(a.rbegin(), a.rend());

    long long beauty = 0;
    for (int i = 0; i < size; i = i * 4 + 1) {
        beauty += a[i];
    }

    cout << beauty << '\n';
}
