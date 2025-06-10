#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n;
        cin >> n;
        int sticks[4 * n];
        for (int i = 0; i < 4 * n; i++)
        {
            cin >> sticks[i];
        }
        sort(sticks, sticks + 4 * n);

        bool condition = true;
        int val = sticks[0] * sticks[(4 * n) - 1];
        for (int i = 0; i < 2 * n; i = i + 2)
        {
            if (!(sticks[i] == sticks[i + 1] && sticks[4 * n - i-1] == sticks[4 * n - i - 2] && val == sticks[i] * sticks[(4 * n) - 1 - i]))
            {
                condition = false;
            }
        }
        if (condition)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}