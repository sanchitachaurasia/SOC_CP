#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n, 0);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    for(long long i = 1; i < n; i++){
        if(a[i] < a[i-1]){
            ans+= a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans;
}