#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    vector<ll> a(N);
    for (ll &x : a) cin >> x;

    sort(a.rbegin(), a.rend());

    ll beauty = 0;
    ll idx = 0;
    ll count = 1;

    while (idx < N-1) {
        idx=0;
        for (ll i = 0; i <count && idx < N; ++i) {
            beauty += a[idx++];
        }
        count *= 4;
    }
    if(N==1){beauty=a[0];}
    cout << beauty << '\n';
}

