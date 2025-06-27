#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b) tie(a, b) = make_pair(b, a % b);
    return a;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    ll area = 1LL * a * b, used;

    if (1LL * a * d <= 1LL * b * c) {
        ll k = a / c;
        used = 1LL * k * c * k * d;
    } else {
        ll k = b / d;
        used = 1LL * k * c * k * d;
    }

    ll empty = area - used, g = gcd(empty, area);
    cout << empty / g << "/" << area / g << "\n";
}
