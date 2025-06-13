#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, n;
    cin >> x >> n;
    
    set<int> lights; // stores positions of lights
    multiset<int> segments; // stores lengths of segments
    
    lights.insert(0);
    lights.insert(x);
    segments.insert(x);

    for (int i = 0; i < n; ++i) {
        int pos;
        cin >> pos;

        auto it = lights.upper_bound(pos);
        int right = *it;
        int left = *prev(it);

        // Remove old segment and add two new ones
        segments.erase(segments.find(right - left));
        segments.insert(pos - left);
        segments.insert(right - pos);

        lights.insert(pos);

        cout << *segments.rbegin() << " ";
    }

    cout << "\n";
    return 0;
}
