#include <iostream>
using namespace std;

int main()
{
    long long int x;
    cin >> x;
    int rem = x % 4;
    int num = x / 4;
    if(x==1){
        cout<<"1";
        return 0;
    }
    if (x < 4)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    if(rem==0){
        for(int i=0;i<num;i++){
            cout<<4*i+3<<" "<<4*i+1<<" "<<4*i+4<<" "<<4*i+2<<" ";
        }
    }
    if(rem==1){
        for(int i=0;i<num;i++){
            cout<<4*i+3<<" "<<4*i+1<<" "<<4*i+4<<" "<<4*i+2<<" ";
        }
        cout<<x;
    }
    if(rem==2){
        cout<<x-1<<" ";
        for(int i=0;i<num;i++){
            cout<<4*i+3<<" "<<4*i+1<<" "<<4*i+4<<" "<<4*i+2<<" ";
        }
        cout<<x;
    }
    if(rem==3){
        cout<<x-1<<" ";
        for(int i=0;i<num;i++){
            cout<<4*i+3<<" "<<4*i+1<<" "<<4*i+4<<" "<<4*i+2<<" ";
        }cout<<x-2<<" ";
        cout<<x;
    }
}
