#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long sum = ((n*(n+1))/2);

    if (n%4==3 || n%4==0) cout << "YES" << "\n";
    else {
        cout << "NO";
        return 0;
    }

    vector <long long> a, b;

    for (long long i=1; i<=n; i++) {
        a.push_back(i);
    }

    sum /= 2;
    long long x = 0;

    while ((x+n)<sum) {
        x += n;
        b.push_back(n);
        a.erase(a.begin()+n-1);
        n--;
    }

    b.push_back(sum-x);
    a.erase(a.begin() + (sum - x - 1));

    cout << b.size() << "\n";
    for (long long i=0; i<b.size(); i++) cout << b[i] << " ";

    cout << "\n";

    cout << a.size() << "\n";
    for (long long i=0; i<a.size(); i++) cout << a[i] << " ";
}