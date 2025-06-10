#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> s;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            s.push_back(t);
        }
        set<int> a;
        for (int i : s)
        {
            a.insert(i);
        }
        if (a.size() > k)
        {
            cout << -1 << "\n";
        }
        else
        {
            vector<int> base;
            bool repeat = false;

            for (int i = 0; i < n && repeat; i++)
            {
                for (int k : base)
                {
                    if (s[i] == k)
                    {
                        repeat = true;
                        break;
                    }
                }
                if (!repeat)
                {
                    base.push_back(s[i]);
                }
            }
            for (int k : a)
            {
                bool found = false;
                for (int b : base)
                {
                    if (b == k)
                    {
                        found == true;
                        break;
                    }
                }
                if (!found)
                {
                    base.push_back(k);
                }
            }
            while (base.size() < k)
            {
                base.push_back(s[0]);
            }
            vector<int> result;

            int i = 0, k = 0;
            while (i < n)
            {
                if (k == base.size())
                {
                    k = 0;
                }
                result.push_back(base[k]);
                if (base[k] == s[i])
                {
                    i++;
                }
                k++;
            }
            cout << result.size() << "\n";
            for (int x : result)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}