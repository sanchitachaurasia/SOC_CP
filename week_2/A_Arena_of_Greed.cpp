#include <bits/stdc++.h>
using namespace std;

using ll = long long;
unordered_map<ll, ll> memo;

ll solve(ll n) {
    if (n == 0) return 0;
    if (memo.count(n)) return memo[n];

    ll res1 = 1 + (n - 1 - solve(n - 1));
    ll res2 = 0;
    if (n % 2 == 0) {
        res2 = n / 2 + (n / 2 - solve(n / 2));
    }
    return memo[n] = max(res1, res2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        cout << solve(N) << '\n';
    }
    return 0;
}
