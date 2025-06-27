#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> count(3);
    for (char c : s) count[c - '0']++;

    int target = n / 3;

    for (int i = 0; i < n; ++i) {
        int digit = s[i] - '0';
        for (int d = 0; d < digit; ++d) {
            if (count[d] < target && count[digit] > target) {
                count[d]++;
                count[digit]--;
                s[i] = char('0' + d);
                break;
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        int digit = s[i] - '0';
        for (int d = 2; d > digit; --d) {
            if (count[d] < target && count[digit] > target) {
                count[d]++;
                count[digit]--;
                s[i] = char('0' + d);
                break;
            }
        }
    }

    cout << s << '\n';
}
