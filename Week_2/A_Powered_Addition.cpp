#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int store[33];
    store[0] = 0;
    store[1] = 1;
    for (int i = 2; i < 32; i++)
    {
        store[i] = 2 * store[i - 1];
    }

    int x;
    cin >> x;
    while (x--)
    {
        int n;
        cin >> n;
        long long int a[n];
        int ans = 0;
        cin >> a[0];
        long long int maxm = a[0];

        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < maxm)
            {
                while (store[ans + 1] <= maxm - a[i])
                {
                    ans++;
                }
            }
            maxm = max(a[i], maxm);
        }
        cout << ans << endl;
    }
}