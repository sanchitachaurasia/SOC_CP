#include <iostream>
using namespace std;

void solution() {
    int n, x;
    cin >> n >> x;

    int bits = __builtin_popcountll(x);

    if (n <= bits) {
        cout << x;
        return;
    }

    int diff = n - bits;
    if (diff % 2 == 0) {
        cout << x + diff;
    } else {
        if (x > 1) {
            cout << x + diff + 1;
        } else if (x == 1) {
            cout << n + 3;
        } else {
            if (n == 1) {
                cout << -1;
            } else {
                cout << n + 3;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        solution();
        cout << '\n';
    }
    return 0;
}
