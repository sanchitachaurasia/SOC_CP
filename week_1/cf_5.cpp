#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int pos_min = -1;
    int min_v = 101;
    int pos_max = -1;
    int max_v = -1;

    for(int i = 0; i < n; i++){
        if(min_v >= a[i]){
            pos_min = i;
            min_v = a[i];
        }
        if(max_v < a[i]){
            pos_max = i;
            max_v = a[i];
        }
    }

    int ans = 0;
    if(pos_max < pos_min){
        ans = pos_max + (n - pos_min - 1);
    } else {
        ans = pos_max + (n - pos_min - 2);
    }
    cout << ans;
}