#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int max=1;
	int num=0;
	bool flag1=false,flag2=false,flag3=false,flag4=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A'){
			if(!flag1){
				num=0;
			}
			flag1=true;
			flag2=false;
			flag3=false;
			flag4=false;
			if(flag1){
				num++;
			}
			if(max<num){
				max=num;
			}
		}
		if(s[i]=='C'){
			if(!flag2){
				num=0;
			}
			flag1=false;
			flag2=true;
			flag3=false;
			flag4=false;
			if(flag2){
				num++;
			}
			if(max<num){
				max=num;
			}
		}
		if(s[i]=='G'){
			if(!flag3){
				num=0;
			}
			flag1=false;
			flag2=false;
			flag3=true;
			flag4=false;
			if(flag3){
				num++;
			}
			if(max<num){
				max=num;
			}
		}
		if(s[i]=='T'){
			if(!flag4){
				num=0;
			}
			flag1=false;
			flag2=false;
			flag3=false;
			flag4=true;
			if(flag4){
				num++;
			}
			if(max<num){
				max=num;
			}
		}
	}
	cout<<max;
}