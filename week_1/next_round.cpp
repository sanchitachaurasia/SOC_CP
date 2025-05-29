#include<iostream>
using namespace std;
 
int main(){
 
    int n,k;
    cin>>n>>k;
    
    int ans = 0;
    int score;
    
    // it is in non-increasing order
    for(int i=1; i<=k; i++){
        cin>>score;
        if(score>0) ans++;
    }
   
    
    int kth_score = INT_MAX;
    if(score>0) kth_score = score;
    
    for(int i=k+1; i<=n; i++){
        cin>>score;
        
        if(score==kth_score)  ans++;
    }
    
    cout<<ans;
}