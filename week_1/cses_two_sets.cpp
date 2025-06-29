#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n%2){
		if(((n+1)/2)%2){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			cout<<n/2+1<<endl;
			for(int i=1;i<=n/2;i+=2){
				cout<<i<<" "<<n-i<<" ";
			}
			cout<<endl<<n/2<<endl;
			for(int i=0;i<=n/2;i+=2){
				if(i==0){
					cout<<n<<" ";
					continue;
				}
				cout<<i<<" "<<n-i<<" ";
			}
		}
	}
	else{
		if((n/2)%2){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			cout<<n/2<<endl;
			for(int i=1;i<=n/2;i+=2){
				cout<<i<<" "<<n+1-i<<" ";
			}
			cout<<endl<<n/2<<endl;
			for(int i=2;i<=n/2;i+=2){
				cout<<i<<" "<<n+1-i<<" ";
			}
		}
	}
}