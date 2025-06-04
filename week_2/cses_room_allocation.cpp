#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int arrival, departure, index;
};

int main() {
    int n;
    cin >> n;
    vector<Customer> customers(n);

    for (int i = 0; i < n; ++i) {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].index = i;
    }

    // Sort customers by arrival time
    sort(customers.begin(), customers.end(), [](Customer a, Customer b) {
        return a.arrival < b.arrival;
    });

    // {departure day, room number}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int room_count = 0;
    vector<int> result(n);

    for (auto cust : customers) {
        if (!pq.empty() && pq.top().first < cust.arrival) {
            // Reuse room
            int room = pq.top().second;
            pq.pop();
            pq.push({cust.departure, room});
            result[cust.index] = room;
        } else {
            // New room needed
            ++room_count;
            pq.push({cust.departure, room_count});
            result[cust.index] = room_count;
        }
    }

    cout << room_count << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";

    return 0;
}
