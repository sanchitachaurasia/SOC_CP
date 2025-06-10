#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    long long powers[40];
    powers[0]=0;
    for(int i=1;i<40;++i){
        powers[i]=pow(2,i-1);
    }
    while(t--){
        int n;
        cin>>n;
        vector<int> given(n);
        int ans=0;
        cin>>given[0];
        int maxm=given[0];
        for(int i=1;i<n;++i){
            cin>>given[i];
            while(powers[ans]<=maxm-given[i]){
                ans++;
            }
            maxm=max(given[i],maxm);
            given[i]=maxm;
        }
        if(ans==0){cout<<0<<endl;}
        else cout<<ans-1<<endl;
    }
}
