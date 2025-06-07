#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
void tell(long long int  n){
    long long int x=n;
    vector<long long int>input;
    for(long long int i=1;i<n+1;i++){
        input.push_back(i);
    }
    if((n*(n+1))%4 !=0){
        cout<<"NO";
        
    }
    else{
        cout<<"YES"<<endl;
        long long int target=n*(n+1)/4;
        long long int i=0;
        unordered_set<long long int> v;;
        while( i !=target){
            if(i+n<target){
                i=i+n;
                v.insert(n);
            }
            else{
                v.insert(target-i);
                i=i+(target-i);
            }
            n=n-1;
        }
        cout<<v.size()<<endl;
        for(long long int  i:v){
            cout<<i<<" ";
        }
        cout<<"\n";
        cout<<x-v.size()<<endl;
        
        for(long long int i:input){
            
            if(v.find(i)==v.end()){
                
                cout<<i<<" ";
            }
        }
        

    }

}
int main(){
    int n;
    cin>>n;
    tell(n);
}