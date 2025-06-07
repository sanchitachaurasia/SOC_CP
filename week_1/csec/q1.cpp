#include<iostream>
using namespace std;
long long int moves_no(int n,long long int arr[]){
    long long int moves=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            moves=moves+(arr[i]-arr[i+1]);
            arr[i+1]=arr[i];
        }
    }
    return moves;
}
int main(){
    int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<moves_no(n,arr);
}