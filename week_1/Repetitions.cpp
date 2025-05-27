#include <iostream>
#include <string>
using namespace std;

int main()
{

    long long int max = 1;
    long long int streak = 1;
    string str;
    cin >> str;
    char prev, curr;
    prev = str[0];

    for (long long int i = 1; i < str.length(); i++)
    {
        curr = str[i];

        if (curr == prev)
        {
            streak++;
        }
        else
        {
            if (streak > max)
            {
                max = streak;
            }
            streak = 1;
        }

        prev = curr;
    }
    if (streak > max)
    {
        max = streak;
    }
    cout << max;
    return 0;
}