#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int i=0, j=1, count=1;

    while (i<s.length() && j<s.length()) {
        while (j<s.length() && s[j]==s[i]) j++;
        count = max(count,(j-i));
        i=j;
    }

    cout << count;
}