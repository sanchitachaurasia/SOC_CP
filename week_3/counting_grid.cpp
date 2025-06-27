#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll modpow(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res=res*a%MOD;
        a = a*a% MOD;
        b>>=1;
    }
    return res;
}

ll modinv(ll a){
    return modpow(a,MOD-2);
}

int main(){
    ll n;
    cin>>n;
    
    ll total = modpow(2,n*n); 
    ll half = modpow(2,(n*n+1)/2);
    ll quarter = modpow(2,(n*n)/4);

    ll result = (total+half+quarter+quarter)%MOD;
    result = result*modinv(4)%MOD;

    cout<<result<<endl;
    return 0;
}
