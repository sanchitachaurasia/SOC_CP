#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int x,y;
		cin>>x>>y;
		long long int r;
		if(x>=y){
			if(x%2){
				r=(x-1)*(x-1)*1LL+y;
			}
			else{
				r=x*x*1LL-y+1;
			}
		}
		else{
			if(y%2){
				r=y*y*1LL-x+1;
			}
			else{
				r=(y-1)*1LL*(y-1)+x;
			}
		}
		cout<<r<<'\n';
	}
}