#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<long long int,long long int>> store(n);
    for(int i=0;i<n;i++){
        cin>>store[i].first>>store[i].second;
    }
    sort(store.begin(),store.end());
    long long int t=0, answer=0;
   for(auto p:store){
    t+=p.first;
    answer+=(p.second-t);
   }
   cout<<answer<<"\n";
    

}