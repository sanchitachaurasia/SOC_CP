#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int arr[26] = {}, m=0;

    for (int i=0; i<s.length(); i++) {
        arr[s[i] - 'a']++;
    }

    for (int i=0; i<26; i++) {
        if (arr[i]!=0) {
            m++;
        }
    }

    if (m%2==1) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";
}