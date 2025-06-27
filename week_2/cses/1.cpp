#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> tasks(n); // {duration, deadline}
    for (int i = 0; i < n; ++i)
        cin >> tasks[i].first >> tasks[i].second;

    sort(tasks.begin(), tasks.end()); // sort by duration

    long long time = 0, reward = 0;
    for (auto &[d, deadline] : tasks) {
        time += d;
        reward += (deadline - time);
    }

    cout << reward << '\n';
}
