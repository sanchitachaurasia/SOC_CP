#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1000005;
vector<int> phi(MAX);

long long modpow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b%2) res=res*a%MOD;
        a = a*a%MOD;
        b/=2;
    }
    return res;
}

long long modinv(long long a){
    return modpow(a,MOD-2);
}

void compute_phi(){
    for(int i=0; i<MAX; i++) phi[i] = i;
    for(int i=2; i<MAX; i++){
        if(phi[i]==i){
            for(int j=i; j<MAX; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;

    compute_phi();

    long long result = 0;
    for(int d=1; d*d<=n; d++){
        if(n%d==0){
            result = (result+phi[d] * modpow(m,n/d)%MOD)%MOD;
            if(d!=n/d)
                result = (result+phi[n/d]*modpow(m, d)%MOD)%MOD;
        }
    }

    result = result*modinv(n)%MOD;
    cout<<result<<endl;
    return 0;
}
