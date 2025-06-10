#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n);
    vector<int> b(n);

    int floorSum = 0;
    vector<int> idxNonInt;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int f = (int)floor(a[i]);
        b[i] = f;
        floorSum += f;

        // Check if a[i] is non-integer (has fractional part)
        if (fabs(a[i] - f) > 1e-9) {
            idxNonInt.push_back(i);
        }
    }

    int diff = -floorSum;  // number of ceilings needed

    for (int i = 0; i < diff; i++) {
        int idx = idxNonInt[i];
        b[idx] += 1;
    }

    // Output
    for (int i = 0; i < n; i++) {
        cout << b[i] << "\n";
    }

    return 0;
}
