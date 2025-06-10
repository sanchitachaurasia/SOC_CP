#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    string s;
    cin>>s;
    vector<int> count(3);
    int x=n/3;
        for (int i = 0; i < n; ++i) {
        count[s[i] - '0']++;
    }
    vector<int> checked(2);
    int idx=0;
    while(count[0]<x){
        if(count[1]>x&&s[idx]=='1'){
            s[idx]='0';
            count[1]--;
            count[0]++;
        }
        if(count[2]>x&&s[idx]=='2'){
            s[idx]='0';
            count[2]--;
            count[0]++;
        }
        idx++;
    }
    idx=0;
        while(count[1]<x){
        if(count[0]>x&&s[idx]=='0'){
            if(checked[0]>x-1){
            s[idx]='1';
            count[0]--;
            count[1]++;}
            else{checked[0]++;}
        }
        if(count[2]>x&&s[idx]=='2'){
            s[idx]='1';
            count[2]--;
            count[1]++;
        }
        idx++;
    }
    idx=0;
    checked[0]=0;
        while(count[2]<x){
        if(count[0]>x&&s[idx]=='0'){
            if(checked[0]>x-1){
            s[idx]='2';
            count[0]--;
            count[2]++;}
            else{checked[0]++;}
        }
        if(count[1]>x&&s[idx]=='1'){
            if(checked[1]>x-1){
            s[idx]='2';
            count[1]--;
            count[2]++;}
            else{checked[1]++;}
        }
        idx++;
    }
    cout<<s<<endl;
}
