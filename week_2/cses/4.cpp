#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<array<int, 3>> guests(n); // {arrival, departure, index}
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        guests[i] = {a, b, i};
    }

    sort(guests.begin(), guests.end());

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    vector<int> room_assign(n);
    int room_count = 0;

    for (auto &[a, b, idx] : guests) {
        if (!pq.empty() && pq.top()[0] < a) {
            int room = pq.top()[1];
            pq.pop();
            room_assign[idx] = room;
            pq.push({b, room});
        } else {
            ++room_count;
            room_assign[idx] = room_count;
            pq.push({b, room_count});
        }
    }

    cout << room_count << '\n';
    for (int x : room_assign)
        cout << x << ' ';
    cout << '\n';
}
