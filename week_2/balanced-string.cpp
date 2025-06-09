#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int x = n / 3;
    vector<int> count(3);
    vector<int> checked(3);

    // Replace extra 0s from left
    for (int i = 0; i < n; ++i) {
        checked[s[i] - '0']++;
        if (s[i] == '0' && checked[0] > x) {
            s[i] = '1';
            checked[0]--;
        }
    }

    // Replace extra 2s from right
    checked = vector<int>(3); // reset
    for (int i = n - 1; i >= 0; --i) {
        checked[s[i] - '0']++;
        if (s[i] == '2' && checked[2] > x) {
            s[i] = '1';
            checked[2]--;
        }
    }

    // Recount
    for (int i = 0; i < n; ++i) {
        count[s[i] - '0']++;
    }

    // Fix '1's to '0' from left
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' && count[0] < x) {
            s[i] = '0';
            count[0]++;
            count[1]--;
        }
    }

    // Fix '1's to '2' from right
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1' && count[2] < x) {
            s[i] = '2';
            count[2]++;
            count[1]--;
        }
    }

    cout << s << endl;
}

