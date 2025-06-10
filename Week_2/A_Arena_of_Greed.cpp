#include <bits/stdc++.h>
using namespace std;
long long int out(long long int x)
{

    if (x == 0)
    {
        return 0;
    }
    else if (x == 1)
    {
        return 1;
    }
    else if (x == 2)
    {
        return 1;
    }
    else if (x == 3)
    {
        return 2;
    }
    else if (x == 4)
    {
        return 3;
    }
    else if (x % 2 == 1)
    {
        return x-out(x - 1);
    }
    else if (x % 4 == 2)
    {
        return x - out(x / 2);
    }
    else
    {
        return x - out(x - 1);
    }
}

int main()
{
    int x;
    cin >> x;
   while(x--) {
       long long int a;
       cin>>a;
       cout<<out(a)<<endl;
    }
}

