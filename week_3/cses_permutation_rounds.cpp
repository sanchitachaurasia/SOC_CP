#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--; // 0-based indexing
    }

    vector<bool> visited(n, false);
    long long lcm = 1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int curr = i, len = 0;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = p[curr];
                len++;
            }
            lcm = lcm / __gcd(lcm, 1LL * len) * len % MOD;
        }
    }

    cout << lcm << "\n";
}
