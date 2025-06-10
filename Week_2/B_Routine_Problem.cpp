#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q, r,s,a ,b ,c ,d;
    cin>>p>>q>>r>>s ;
    if(p*s>q*r){
        a=r*p;
        b=r*q;
        c=a;
        d=p*s;
        c=d-b;
        a=__gcd(d,c);
        c=c/a;
        d=d/a;
        cout<<c<<"/"<<d<<endl;


        

    }else if(p*s<q*r){
        swap(p,q);
        swap(r,s);

        a=r*p;
        b=r*q;
        c=a;
        d=p*s;
        c=d-b;
        a=__gcd(d,c);
        c=c/a;
        d=d/a;
        cout<<c<<"/"<<d<<endl;


        

    }
    else  cout<<"0/1"<<endl;
}