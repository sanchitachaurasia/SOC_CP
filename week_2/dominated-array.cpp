#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;
        vector<int> given(n);
        for (int m = 0; m < n; ++m)
        {
            cin >> given[m];
        }
        if (n < 2)
        {
            cout << -1 << endl;
        }
        else
        {
            unordered_map<int, int> hehe;
            int ans = 2e9;
            for (int m = 0; m < n; ++m)
            {
                if (hehe[given[m]])
                {
                    ans = min(ans, m - hehe[given[m]] + 2);
                }
                hehe[given[m]] = m + 1;
            }
            if (ans == 2e9)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
    }
}

