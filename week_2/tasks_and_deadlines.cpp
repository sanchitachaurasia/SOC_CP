#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tasks.push_back({x, y});
    }

    sort(tasks.begin(), tasks.end());

    long long f = 0, rew = 0;

    for (auto it : tasks) {
        f += it.first;
        rew += (it.second - f);
    }

    cout << rew << "\n";
}
