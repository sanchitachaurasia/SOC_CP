//permutations 
#include<iostream>
using namespace std;
void tell(long long int n){
    if(n==3  || n==2){
        cout<<"NO SOLUTION";
    }
    else if (n==4){
        cout<<2<<" "<<4<<" "<<1<<" "<<3;
    }
    else{
        if(n%2!=0){
            for(long long int i=1;i<=n;i=i+2){
                cout<<i<<" ";
            }
            for(long long int i=2;i<n;i=i+2){
                cout<<i<<" ";
            }
        }
        if(n%2==0){
            for(long long int i=1;i<n;i=i+2){
                cout<<i<<" ";
            }
            for(long long int i=2;i<=n;i=i+2){
                cout<<i<<" ";
            }
        }
    }
}
int main(){
    long long int n;
    cin>>n;
    tell(n);
}