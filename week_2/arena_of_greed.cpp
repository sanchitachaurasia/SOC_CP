#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll max_coins(ll n) {
    ll chanek = 0;
    bool turn = true; // true for Mr. Chanek, false for opponent

    while (n > 0) {
        ll take = 0;

        if (n % 2 == 1) {
            take = 1;
        } else if (n % 4 != 0 || n == 4) {
            take = n / 2;
        } else {
            take = 1;
        }

        if (turn) chanek += take;
        n -= take;
        turn = !turn;
    }

    return chanek;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << max_coins(n) << '\n';
    }

    return 0;
}
