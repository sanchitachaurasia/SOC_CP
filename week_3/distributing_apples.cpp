#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;

int main(){

    int n,m;
    cin>>n>>m;

    vector<long long> fact(MAX), inv_fact(MAX);
    fact[0]=1;

    for(int i=1; i<=n+m; i++)
        fact[i] = fact[i-1]*i%MOD;

    inv_fact[n+m]=1;
    long long base = fact[n+m], exp=MOD-2;
    while(exp >0) {
        if(exp&1)
            inv_fact[n+m] = inv_fact[n+m]*base%MOD;
        base = base*base%MOD;
        exp>>=1;
    }

    for(int i=n+m-1; i>=0; i--)    inv_fact[i] = inv_fact[i+1]*(i+1)%MOD;

    long long res = fact[n+m-1]*inv_fact[m]%MOD*inv_fact[n-1]%MOD;
    cout<<res<<endl;

    return 0;
}
