#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long moves=0;
    cin >> n;
    int arr[n];
    cin >> arr[0];

    for (int i=1; i<n; i++) {
        cin >> arr[i];
        if (arr[i]<arr[i-1]) {
            moves += (arr[i-1]-arr[i]);
            arr[i] = arr[i-1];
        }
    }

    cout << moves;
}