#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int min;
	long long int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i==0){
			min=arr[0];
		}
		else{
			if(arr[i]<min){
				sum+=min-arr[i];
			}
			else{
				min = arr[i];
			}
		}
	}
	cout<<sum;
}