#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    string s;
    cin >> s;
    map<char, int> sol;
    for (int i = 0; i < s.size(); ++i)
    {
        sol[s[i]]++;
    }
    if (sol.size() % 2 == 0)
    {
        cout << "CHAT WITH HER!" << endl;
    }
    else
    {
        cout << "IGNORE HIM!" << endl;
    }
}
