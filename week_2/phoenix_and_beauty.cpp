#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        set<int> base;
        for(int i=0; i<n; i++){
            cin>>a[i];
            base.insert(a[i]);
        }

        if(base.size()>k){
            cout<<-1<<endl;
            continue;
        }

        vector<int> block(base.begin(),base.end());
        while(block.size()<k){
            block.push_back(1);
        }

        vector<int> result;
        while(result.size()<n*k){
            for(int x:block){
                result.push_back(x);
            }
        }

        cout<<result.size()<<endl;
        for(int x:result) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}
