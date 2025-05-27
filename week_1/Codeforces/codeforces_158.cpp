#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	cin.ignore();
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum =k;
	if(a[k-1]==0){
		sum--;
		for(int i=k-2;i>=0;i--){
			if(a[i]!=0){
				break;
			}
			sum--;
		}
		cout<<sum;
	}
	else{
		for(int i=k;i<n;i++){
			if(a[i]==a[k-1]){
				sum++;
			}
			else{
				break;
			}
		}
		cout<<sum;
	}
}