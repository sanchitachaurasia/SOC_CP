#include <iostream>
using namespace std;

int main()
{
    long int x;
    cin >> x;
    while (x--)
    {
        long long int a, b;
        cin >> a >> b;
        if (a < b)
        {
            if (b % 2 == 1)
            {
                cout << (b * b) - a + 1 << endl;
            }
            else
                cout << ((b - 1) * (b - 1)) + a << endl;
        }
        else
        {
            if (a % 2 == 0)
            {
                cout << (a * a) - b + 1 << endl;
            }
            else
                cout << (a - 1) * (a - 1) + b << endl;
        }
    }
}