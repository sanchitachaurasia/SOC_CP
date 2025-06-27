#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9+7;
const int MAX = 1e6+5;

int main(){
    int n;
    cin>>n;

    vector<long long> derange(n+1);
    derange[0]=1;      // technically D(0) = 1 (for formula consistency)
    if(n>=1) derange[1]=0;
    if(n>=2) derange[2]=1;

    for(int i=3; i<=n; i++){
        derange[i] = (i-1) * (derange[i-1] + derange[i-2])%MOD;
    }

    cout<<derange[n]<<endl;
    return 0;
}
