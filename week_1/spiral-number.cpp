#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    vector<long> soln;
    for(int i=0;i<t;++i){
        long y,x;
        long ans;
        cin>>y>>x;
        if(x>=y){
            if(x%2==0){ans=(x-1)*(x-1)+y;}
            else {ans=x*x-y+1;}
        }
        else{
            if(y%2==0){ans=y*y-x+1;}
            else {ans=(y-1)*(y-1)+x;}
        }
        soln.push_back(ans);
    }
    for(int i=0;i<t;++i){
        cout<<soln[i]<<endl;
    }
}

