#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main(){
    string s;
    cin >> s;

    unordered_set<char> diff;
    for(int i = 0; i < s.size(); i++){
        diff.insert(s[i]);
    }

    if(diff.size()%2 == 0) cout << "CHAT WITH HER!";
    else{
       cout << "IGNORE HIM!";
    }
}