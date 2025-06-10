#include<iostream>
#include<vector>
using namespace std;
long long int paired(long long int n){
    return n*(n-1)/2;
}
int main(){
    long long int n,m;
    cin>>n>>m;
    long long a,b;
    b=(n-m+1)*(n-m)/2;
    a=(n%m)*paired((n/m)+1)+(m-(n%m))*paired((n/m));
    cout<<a<<" "<<b<<endl;
}
