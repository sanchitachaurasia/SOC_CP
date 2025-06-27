#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2000005;
vector<long long> fact(MAX), inv_fact(MAX);

long long modinv(long long a) {
    long long res = 1, p = MOD - 2;
    while(p){
        if(p%2)res=res*a% MOD;
        a=a*a%MOD;
        p/=2;
    }
    return res;
}

int main(){

    int n;
    cin>>n;

    if(n%2!=0){
        cout<<0<<endl;
        return 0;
    }

    fact[0] = 1;
    for(int i=1; i<MAX; i++)
        fact[i] = fact[i-1]*i%MOD;

    inv_fact[MAX-1] = modinv(fact[MAX-1]);
    for(int i=MAX-2; i>=0; i--)
        inv_fact[i] = inv_fact[i+1]*(i+1)%MOD;

    int k = n/2;
    long long catalan = fact[2*k]*inv_fact[k]%MOD*inv_fact[k+1]%MOD;
    cout<<catalan<<endl;

    return 0;
}
