#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	int idx=0;
	while(1){
		cin>>x;
		if(x){
			break;
		}
		idx++;
	}
	cout<<(abs(2-idx/5)+abs(2-idx%5));
}