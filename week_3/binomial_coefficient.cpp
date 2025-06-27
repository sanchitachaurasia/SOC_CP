#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int main(){

    vector<long long> fact(MAX), inv_fact(MAX);
    fact[0] = 1;
    for(int i=1; i<MAX; i++)
        fact[i] = fact[i-1] * i%MOD;

    inv_fact[MAX-1] = 1;
    long long base = fact[MAX-1], exp=MOD-2;
    while(exp>0){
        if(exp%2==1)
            inv_fact[MAX-1]=inv_fact[MAX-1]*base% MOD;
        base=base*base%MOD;
        exp/=2;
    }

    for(int i=MAX-2; i>=0; i--)
        inv_fact[i] = inv_fact[i+1]*(i+1)%MOD;

    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(b<0 || b>a){
            cout<<0<<endl;
            continue;
        }
        long long res=fact[a]*inv_fact[b]%MOD*inv_fact[a-b]%MOD;
        cout<<res<<endl;
    }

    return 0;
}
