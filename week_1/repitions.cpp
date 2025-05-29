#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long n=s.size();
    long long max=0;
    long long count=1;
    for(long long i=0;i<n;++i){
        if(i>0&&s[i]==s[i-1]){++count;}
        else if(i>0&&s[i]!=s[i-1]){count=1;}
        if(max<count){max=count;}
    }
    cout<<max<<endl;
}
