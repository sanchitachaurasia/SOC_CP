#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int getMinSeconds(vector<int>& a){
    int maxGap = 0;
    int n = a.size();
    int currentMax = a[0];

    for(int i=1; i<n; i++){
        if(a[i]<currentMax){
            maxGap = max(maxGap,currentMax-a[i]);
        } 
        else{
            currentMax = a[i];
        }
    }

    int seconds = 0;
    while((1LL<<seconds)<=maxGap){
        seconds++;
    }

    return seconds;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);

        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        cout<<getMinSeconds(a)<<endl;
    }

    return 0;
}
