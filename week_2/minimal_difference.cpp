#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        vector<int> a;

        cin >> n;
        a.resize(n);
        
        for(int i = 0; i < n; i++) cin >> a[i];

        int ans = INT_MAX;
        vector<int> l(n + 1, -1);
        for(int i = 0; i < n; i++) {
            if(l[a[i]] != -1)
                ans = min(ans, i - l[a[i]] + 1);
            l[a[i]] = i;
        }
        if(ans > n)
            ans = -1;
        cout << ans << endl;

    }
}