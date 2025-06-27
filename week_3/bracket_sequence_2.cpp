#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2000005;

vector<long long> fact(MAX), inv_fact(MAX);

long long modinv(long long a){
    long long res=1, p=MOD-2;
    while(p){
        if(p&1) res=res*a%MOD;
        a = a*a%MOD;
        p>>=1;
    }
    return res;
}

long long binom(int a, int b){
    if(b<0 || b>a) return 0;
    return fact[a]*inv_fact[b]%MOD * inv_fact[a-b]% MOD;
}

int main(){
    int n;
    string prefix;
    cin>>n>>prefix;

    if(n%2!=0){
        cout<<0<<endl;
        return 0;
    }

    int k = prefix.size();
    int open=0, close=0;
    for(char c:prefix){
        if(c=='(') open++;
        else close++;
        if(close>open){
            cout<<0<<endl;
            return 0;
        }
    }

    int rem = n-k;
    int need_open = n/2-open;
    int need_close = n/2-close;

    if(need_open<0 || need_close<0){
        cout<<0<<endl;
        return 0;
    }

    fact[0] = 1;
    for(int i=1; i<MAX; i++)
        fact[i] = fact[i-1]*i%MOD;

    inv_fact[MAX-1] = modinv(fact[MAX-1]);
    for(int i=MAX-2; i>=0; i--)
        inv_fact[i] = inv_fact[i+1]*(i+1)%MOD;

    if(open-close>need_close){
        cout<<0<<endl;
        return 0;
    }

    long long total = binom(need_open+need_close,need_open);
    long long invalid = binom(need_open+need_close,need_open-1);
    long long ans =(total-invalid+MOD)%MOD;

    cout<<ans<<endl;
    return 0;
}
