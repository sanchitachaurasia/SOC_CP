#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int m, n;
    cin >> n >> m;
    long long int minm, maxm;
    maxm = ((n - m + 1) * (n - m )) / 2;
    long long int val = n / m;
    long long int gap = n - val * m;
    minm = (m - gap) * (val * (val - 1)) / 2 + gap * (val * (val + 1)) / 2;
    cout << minm << " " << maxm;
}