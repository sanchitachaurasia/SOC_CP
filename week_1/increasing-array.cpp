#include <iostream>
#include <vector>
using namespace std;

int main(){
    long n;
    cin>>n;
    vector<long> arr(n);
    long count=0;
    for(long i=0;i<n;++i){
        cin>>arr[i];
        if(i>0&&arr[i]-arr[i-1]<0){count+=arr[i-1]-arr[i];
        arr[i]=arr[i-1];}
    }
    cout<<count<<endl;
}
