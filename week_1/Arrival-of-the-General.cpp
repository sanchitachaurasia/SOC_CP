#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    cin>>arr[0];
    int max=arr[0],min=arr[0];
    int m,p;
    for(int i=1;i<n;++i){
        cin>>arr[i];
        if(max<arr[i]){max=arr[i];m=i;}
        if(min>=arr[i]){min=arr[i];p=i;}
    }
    if(m>p){cout<<(m+n-p-2)<<endl;}
    else cout<<(m+n-p-1)<<endl;
}

