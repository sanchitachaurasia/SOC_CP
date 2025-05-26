#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, mini=0, maxi=0, minnum=INT_MAX, maxnum=INT_MIN, a=0;
    cin >> n;
    int arr[n];

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i]<minnum) {
            minnum = arr[i];
        }
        if (arr[i]>maxnum) {
            maxnum = arr[i];
        }
    }

    for (int i=0; i<n; i++) {
        if (arr[i]==maxnum) {
            maxi = i;
            break;
        }
    }

    for (int i=n-1; i>=0; i--) {
        if (arr[i]==minnum) {
            mini = i;
            break;
        }
    }

    if (mini < maxi) a=1;
    cout << maxi + n - mini - 1 - a;
}