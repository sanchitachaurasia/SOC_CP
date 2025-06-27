#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        unordered_map<int,int> map;
        int min_size = INT_MAX;
        
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
            
            if(map.count(arr[i])){
                int len = i - map[arr[i]] + 1;
                min_size = min(min_size, len);
            }
            
            map[arr[i]] = i;
        }
        
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        
        else{
            cout<<min_size<<endl;
        }
    }
    
    
    return 0;
}
