#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int sum=0;
	unordered_map<char,bool> check;
	for(int i=0;i<s.size();i++){
		check[s[i]]=true;
	}
	for(int i=0;i<s.size();i++){
		if(check[s[i]]){
			check[s[i]]=false;
			sum++;
		}
	}
	if(sum%2){
		cout<<"IGNORE HIM!";
	}
	else{
		cout<<"CHAT WITH HER!";
	}
}