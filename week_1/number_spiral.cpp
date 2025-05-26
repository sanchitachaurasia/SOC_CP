#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        long long row, col;
        cin >> row >> col;
        
        long long g = max(row,col);
        long long ans;

        if (g==col && g%2==1) {
            ans = (g*g - row + 1);
        }
        else if (g==row && g%2==1) {
            ans = ((g-1)*(g-1) + col);
        }
        else if (g==col && g%2==0) {
            ans = ((g-1)*(g-1) + row);
        }
        else if (g==row && g%2==0) {
            ans = (g*g - col + 1);
        }
        cout << ans << endl;
    }
}