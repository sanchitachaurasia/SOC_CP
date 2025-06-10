#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = n / 3;

    string s;
    cin >> s;
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            zero++;
        }
        if (s[i] == '1')
        {
            one++;
        }
        if (s[i] == '2')
        {
            two++;
        }
    }
    int i = n - 1;
    while (zero > x)
    {
        if (s[i] == '0')
        {
            if (two < x)
            {
                s[i] = '2';
                zero--;
                two++;
            }
            else
            {
                s[i] = '1';
                one++;
                zero--;
            }
        }
        i--;
    }
    i = 0;
    while (two > x)
    {
        if (s[i] == '2')
        {
            if (zero < x)
            {
                s[i] = '0';
                zero++;
                two--;
            }
            else
            {
                s[i] = '1';
                one++;
                two--;
            }
        }
        i++;
    }
    i = 0;
    while (one > x && zero < x)
    {
        if (s[i] == '1')
        {
            if (zero < x)
            {
                s[i] = '0';
                zero++;
                one--;
            }
        }
        i++;
    }
    i = n - 1;
    while (one > x)
    {
        if (s[i] == '1')
        {

            s[i] = '2';
            one--;
            two++;
        }
        i--;
    }
    cout << s << endl;
}