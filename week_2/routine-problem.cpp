#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void reduce(int a,int b){
    int temp=a;
    a=a/__gcd(a,b);b=b/__gcd(temp,b);
    cout<<a<<"/"<<b<<endl;
}
int main(){
    float a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a/b>=c/d){
        reduce(a*d-b*c,a*d);
    }
    else{
        reduce(b*c-a*d,b*c);
    }
}
