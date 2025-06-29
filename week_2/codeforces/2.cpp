#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }

    int sasha = 0, dima = 0;
    long long total = 0;

    for (int i = 1; i <= n; ++i) {
        int p1 = pos[i][0];
        int p2 = pos[i][1];

        // Try both assignments
        long long option1 = abs(sasha - p1) + abs(dima - p2);
        long long option2 = abs(sasha - p2) + abs(dima - p1);

        if (option1 <= option2) {
            total += option1;
            sasha = p1;
            dima = p2;
        } else {
            total += option2;
            sasha = p2;
            dima = p1;
        }
    }

    cout << total << '\n';
}
