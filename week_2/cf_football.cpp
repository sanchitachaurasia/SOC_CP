#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        long long chanek = 0;
        bool is_chanek_turn = true;

        while (N > 0) {
            long long taken;
            if (N % 2 == 0)
                taken = N / 2;
            else
                taken = 1;

            if (is_chanek_turn)
                chanek += taken;

            N -= taken;
            is_chanek_turn = !is_chanek_turn;
        }

        cout << chanek << '\n';
    }

    return 0;
}
