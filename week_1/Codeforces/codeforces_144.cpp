#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int max=0;
	int min=101;
	int maxid=0;
	int minid=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>max){
			max =arr[i];
			maxid=i;
		}
		if(arr[i]<=min){
			min =arr[i];
			minid=i;
		}
	}
	int sum=0;
	if(minid>=maxid){
		sum = maxid+n-1-minid;
	}
	else{
		sum = maxid+n-2-minid;
	}
	cout<<sum;
}