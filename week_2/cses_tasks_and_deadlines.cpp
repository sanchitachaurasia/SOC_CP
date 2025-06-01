#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second; // duration, deadline
    }

    // Sort tasks by duration (ascending)
    sort(tasks.begin(), tasks.end());

    long long current_time = 0;
    long long total_reward = 0;

    for (auto& task : tasks) {
        current_time += task.first;
        total_reward += task.second - current_time;
    }

    cout << total_reward << "\n";
    return 0;
}

