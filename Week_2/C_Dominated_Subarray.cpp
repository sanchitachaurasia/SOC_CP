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
        vector<int> storage(n);
        for (int i = 0; i < n; i++)
        {
            cin >> storage[i];
        }

        unordered_map<int, int> lastIndex;
        int minlength = INT_MAX;
        int back = 0;

        for (int i = 1; i < n+1; i++)
        {
            if (lastIndex[storage[i-1]]>back)
            {
                int currlength = i - lastIndex[storage[i-1]] + 1;
                minlength = min(minlength, currlength);back=lastIndex[storage[i-1]];
            }
            lastIndex[storage[i-1]] = i;
            
        }

        if (minlength == INT_MAX)
            cout << -1 << "\n";
        else
            cout << minlength << "\n";
    }
}
