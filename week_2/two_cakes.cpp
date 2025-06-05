#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    vector<pair<int, int>> positions(n + 1); // Each size appears exactly twice

    // Reading input and storing positions of each size
    vector<int> count(n + 1, 0); // To track first/second occurrence
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        int val = a[i];
        if (count[val] == 0)
            positions[val].first = i;
        else
            positions[val].second = i;
        count[val]++;
    }

    int sasha_pos = 0;
    int dima_pos = 0;
    long long total_distance = 0;

    for (int x = 1; x <= n; ++x) {
        int p1 = positions[x].first;
        int p2 = positions[x].second;

        // Two options: Sasha -> p1, Dima -> p2  OR  Sasha -> p2, Dima -> p1
        int option1 = abs(p1 - sasha_pos) + abs(p2 - dima_pos);
        int option2 = abs(p2 - sasha_pos) + abs(p1 - dima_pos);

        if (option1 <= option2) {
            total_distance += option1;
            sasha_pos = p1;
            dima_pos = p2;
        } else {
            total_distance += option2;
            sasha_pos = p2;
            dima_pos = p1;
        }
    }

    cout << total_distance << endl;

    return 0;
}
