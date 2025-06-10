#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<double> given(n);
    double fractionpart=0;
    for(int i=0;i<n;++i){
        cin>>given[i];
        fractionpart+=(given[i]-double(floor(given[i])));
    }
    fractionpart=round(fractionpart);
    for(int i=0;i<n;++i){
        if(fractionpart>0&&given[i]!=floor(given[i])){given[i]=floor(given[i])+1;--fractionpart;}
        given[i]=floor(given[i]);
    }
    for(auto x:given){
        cout<<x<<endl;
    }
}
