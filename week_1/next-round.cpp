#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> marks(n);
    for(int i=0;i<n;++i){
        cin>>marks[i];
    }
    int i;
    for(i=0;i<n;++i){
        if(marks[i]<marks[k-1]||marks[i]<=0)break;
    }
    if(n==1&&marks[0]>0){cout<<1<<endl;}
    if(n==1&&marks[0]<=0){cout<<"0"<<endl;}
    if(n!=1){cout<<i<<endl;}
}
