#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	if(n==2||n==3){
		cout<<"NO SOLUTION";
	}
	else if(n%2){
		arr[n/2]=n/2+1;
		for(int i=1;i<=n/2;i++){
			if(i==1){
				arr[n/2-i]=i;
				arr[n/2+i]=n-i+1;				
			}
			else{
				arr[n/2-i]=arr[n/2+i-1]-pow(-1,i);
				arr[n/2+i]=arr[n/2-i+1]+pow(-1,i);
			}
		}
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
	}
	else{
		for(int i=0;i<n/2;i++){
			if(i==0){
				arr[n/2-i-1]=i+1;
				arr[n/2+i]=n-i;				
			}
			else{
				arr[n/2-i-1]=arr[n/2+i-1]+pow(-1,i);
				arr[n/2+i]=arr[n/2-i]-pow(-1,i);
			}
		}
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
	}
}