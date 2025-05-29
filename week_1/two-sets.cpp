#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> A;
    vector<int> B;
    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        for (int i = n; i > 0; i = i - 4)
        {
            B.push_back(i);
            A.push_back(i - 1);
            A.push_back(i - 2);
            if (i >=4)
            {
                B.push_back(i - 3);
            }
        }
    }
    reverse(B.begin(), B.end());
    reverse(B.begin(), B.end());
    cout << "YES" << endl;
    cout << A.size() << endl;
    for (auto x : A)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << B.size() << endl;
    for (auto x : B)
    {
        cout << x << " ";
    }
    cout << endl;
}
