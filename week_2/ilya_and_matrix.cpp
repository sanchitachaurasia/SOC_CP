#include <bits/stdc++.h>
using namespace std;

int main() {
    long long size; // 4^n
    cin >> size;

    vector<long long> a(size);
    for (long long i = 0; i < size; i++) cin >> a[i];

    sort(a.rbegin(), a.rend()); // sort descending

    long long n = 0;
    long long temp = size;
    while (temp > 1) {
        temp /= 4;
        n++;
    }

    long long answer = 0;
    long long index = 0;
    long long groupSize = 1;
    for (long long depth = 0; depth <= n; depth++) {
        long long times = n + 1 - depth;
        for (long long i = 0; i < groupSize; i++) {
            answer += a[index++] * times;
        }
        groupSize *= 4;
    }

    cout << answer << "\n";
    return 0;
}
