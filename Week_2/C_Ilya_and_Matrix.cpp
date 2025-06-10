#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> store(n);
    for (int i = 0; i < n; i++)
    {
        cin >> store[i];
    }
    sort(store.begin(), store.end());
    reverse(store.begin(), store.end());
    long long int sum = 0;
    int x = n, t = 0;
    while (x > 1)
    {
        t++;
        x /= 4;
    }
    int curr = 1;
    int a = t + 1;

    for (int i = 0; i < n; i++)
    {
        if (i == curr)
        {
            curr *= 4;
            a--;
        }
        sum += (long long int)a * store[i];
    }

    cout << sum;
}