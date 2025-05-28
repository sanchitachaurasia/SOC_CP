#include <iostream>
using namespace std;
 
long long int func(long long int x, long long int y){
    if (x >= y)
    {
        if (x%2 == 0)
        {
            return (x-1)*(x-1)+y;
        }
        else{
            return (x)*(x)-y+1;
        }
        
    }
 
    else{
        if (y%2 == 0)
        {
            return (y)*(y)-x+1;
        }
        else
        {
            return (y-1)*(y-1)+x;
        }
        
        
    }
 
}
 
int main()
{
    /*here maybe let's make a formula, f(x,y) = ans and we have to find this f(x,y)*/
    long long int itt;
    cin>>itt;
    for (long long int i = 0; i < itt; i++)
    {
        long long int x,y;
        cin >>y;
        cin >>x;
        cout<< func(x,y)<<endl;
    }
    return 0;
}
