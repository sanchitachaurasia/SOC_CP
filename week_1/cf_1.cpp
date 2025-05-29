#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> scores(n, 0);
    for(int i = 0; i < n; i++){
        cin >> scores[i];
    }

    int score_to_beat = scores[k-1];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(scores[i] >= score_to_beat && scores[i] > 0) ans++;
    }
    cout << ans;
}