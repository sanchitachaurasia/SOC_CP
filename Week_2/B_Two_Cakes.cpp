#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int first[n], second[n];
    vector<bool>filled(n,false);
    for (int i = 0; i < 2 * n; i++)
    {
        int t;
        cin >> t;
        if (filled[t - 1])
        {
            second[t - 1] = i;
        }
        else
        {
            first[t - 1] = i;
            filled[t - 1] = true;
        }
    }
    int long long sum = first[0] + second[0];
    for (int i = 1; i < n; i++)
    {
        sum += min((abs(first[i] - first[i - 1]) + abs(second[i] - second[i - 1])), (abs(second[i] - first[i - 1]) + abs(first[i] - second[i - 1])));
    }
    cout << sum;
}