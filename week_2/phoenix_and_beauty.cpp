#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        set<int> distinct_numbers;
        for (int i = 0; i < N; i++) {
            int a; 
            cin >> a;
            distinct_numbers.insert(a);
        }

        if ((int)distinct_numbers.size() > K) {
            cout << -1 << "\n";
            continue;
        }

        cout << N * K << "\n";

        for (int i = 0; i < N; i++) {
            for (int x : distinct_numbers)
                cout << x << " ";
            for (int j = 0; j < K - (int)distinct_numbers.size(); j++)
                cout << 1 << " ";
        }
        cout << "\n";
    }
}
