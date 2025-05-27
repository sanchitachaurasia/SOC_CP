#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }
    int min = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[min] > arr[i])
        {
            min = i;
        }
    }
    if (max <= min)
    {
        cout << max + n - min - 1;
    }
    else
    {
        cout << max + n - min - 2;
    }
}