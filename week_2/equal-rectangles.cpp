#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int n;
        cin>>n;
        vector<int> sides(4*n);
        for(int m=0;m<4*n;++m){
            cin>>sides[m];
        }
        sort(sides.begin(),sides.end());
        int ans=sides[0]*sides[4*n-1];
        bool check=true;
        for(int m=0;m<2*n;m+=2){
            (sides[m]*sides[4*n-1-m]==ans&&sides[m+1]==sides[m]&&sides[4*n-1-m]==sides[4*n-2-m])?:check=false;
        }
        if(check)cout<<"YES"<<endl;
        else{cout<<"NO"<<endl;}
    }
}
