#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    int count = 0;
    string str;
    cin >> str;
    vector<char> store;
    for (int i = 0; i < str.length(); i++)
    {
        int j;
        for (j = 0; j < store.size(); j++)
        {
            if (str[i] == store[j])
            {
                break;
            }
        }
        if (j == store.size())
        {
            count++;
            store.push_back(str[i]);
        }
    }

    if (count % 2 == 0)
    {
        cout << "CHAT WITH HER!";
    }
    else
        cout << "IGNORE HIM!";
}