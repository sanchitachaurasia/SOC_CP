#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr1[n], arr2[n];

    vector<tuple<int, int, int>> allo(n);

    for (int i=0; i<n; i++) {
        cin >> arr1[i] >> arr2[i];
        allo[i] = {arr1[i],arr2[i],i};
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    sort(allo.begin(), allo.end(), [](auto &a, auto &b) {
        if (get<0>(a) == get<0>(b)) {
            if (get<1>(a) == get<1>(b)) 
                return get<2>(a) > get<2>(b);
            return get<1>(a) < get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    });

    long long rooms=1, cnt=1;
    int i=1, j=0;

    while (i<n && j<n) {
        if (arr1[i]<=arr2[j]) {
            cnt++;
            i++;
        }
        else {
            cnt--;
            j++;
        }
        rooms = max(rooms,cnt);
    }

    int vac[rooms] = {};

    for (auto &t : allo) {
        int chIn = get<0>(t);
        int chOut = get<1>(t);
        int idx = get<2>(t);

        for (int k=0; k<rooms; k++) {
            if (chIn > vac[k]) {
                vac[k] = chOut;
                arr1[idx] = k+1;
                break;
            }
        }
    }

    cout << rooms << "\n";
    for (int k=0; k<n; k++)
        cout << arr1[k] << " ";
}