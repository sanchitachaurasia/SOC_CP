#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int count = 0;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            if (a[i] >= a[k - 1])
            {
                count++;
            }
        }
    }

    cout << count;
}