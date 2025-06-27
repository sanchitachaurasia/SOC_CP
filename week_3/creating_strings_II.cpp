#include <iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int main() {

    string s;
    cin>>s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c: s) freq[c-'a']++;

    vector<long long> fact(MAX), inv_fact(MAX);
    fact[0] = 1;
    for(int i=1; i<=n; i++)
        fact[i] = fact[i-1]*i%MOD;

    inv_fact[n] = 1;
    long long base = fact[n], exp=MOD-2;
    while(exp>0){
        if (exp %2==1)
            inv_fact[n] = inv_fact[n] * base % MOD;
        base = base*base%MOD;
        exp/=2;
    }

    for(int i=n-1; i>=0; i--)
        inv_fact[i] = inv_fact[i+1]*(i+1)%MOD;

    long long res = fact[n];
    for(int i=0; i<26; i++){
        res=res*inv_fact[freq[i]]%MOD;
    }

    cout<<res<<endl;

    return 0;
}
