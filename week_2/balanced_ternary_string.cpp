#include<bits/stdc++.h>
using namespace std;

int needRep(const vector<int> &cnt, const vector<int> &need) {
    int res = 0;
    for (int i = 0; i < 3; ++i)
        res += abs(cnt[i] - need[i]);
    assert(res % 2 == 0);
    return res / 2;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(3, 0), cur(3, n / 3);

    // Count how many '0', '1', '2' in s
    for (char c : s) 
        ++cnt[c - '0'];

    int need = needRep(cnt, cur);
    int curRep = 0;

    for (int i = 0; i < n; ++i) {
        --cnt[s[i] - '0'];
        for (int j = 0; j < 3; ++j) {
            if (cur[j] == 0) continue;

            int rep = (j != s[i] - '0') ? 1 : 0;
            --cur[j];

            if (curRep + rep + needRep(cnt, cur) == need) {
                s[i] = j + '0';
                curRep += rep;
                break;
            }

            ++cur[j];
        }
    }

    cout << s << "\n";

    return 0;
}
