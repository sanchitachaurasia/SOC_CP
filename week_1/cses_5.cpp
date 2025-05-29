#include <iostream>
using namespace std;
 
int main()
{
    long int size;
    cin>>size;
    long int arr[size];
 
    for (long int i = 0; i < (size%2 + size/2); i++)
    {
        arr[i] = 2*i + 1;
    }
 
    for (long int i = (size%2 + size/2); i < size; i++)
    {
        arr[i] = 2*(i + 1 - (size%2 + size/2));
    }
 
 
    if (size == 2 ||size == 3)
    {
        cout<<"NO SOLUTION";
    }
 
    else if (size == 4) {
        cout << 2<<" "<<4<<" "<<1<<" "<<3;
    }
 
    else{
        for (long int i = 0; i < size; i++)
        {
            cout << arr[i] <<" ";
        }
        
    }
    
    
    
}