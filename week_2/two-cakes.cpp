#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,pair<int,int>> pattern;
    vector<int> arr(2*n);
    for(int i=0;i<2*n;++i){
        cin>>arr[i];
        if(pattern[arr[i]].first){pattern[arr[i]].second=i+1;}
        else pattern[arr[i]].first=i+1;
    }
    long long ans=0;
    int a=1,b=1;
    for(auto p:pattern){
        ans+=min(abs(p.second.first-a)+abs((p.second.second)-b),abs(p.second.first-b)+abs(p.second.second-a));
        a=p.second.first;
        b=p.second.second;
    }
    cout<<ans<<endl;
}
