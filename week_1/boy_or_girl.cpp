#include<iostream>
#include<vector>
using namespace std;
 
int main(){
 
    string str;
    cin>>str;
    
    vector<bool> count(26,false);
    int size = str.size();
    
    for(int i=0; i<size; i++){
        count[str[i]-'a'] = true;
    }
    
 
    bool female = true;
    
    for(int i=0; i<26; i++){
        if(count[i]) female=!female;
    }
    
    if(female) cout<<"CHAT WITH HER!";
    else  cout<<"IGNORE HIM!";
    
    return 0;
}