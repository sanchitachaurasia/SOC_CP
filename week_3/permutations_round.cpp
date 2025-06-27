#include<iostream>
#include<vector>
#include<numeric>
#include<limits.h>
using namespace std;

const int MOD = 1e9+7;

long long lcm(long long a,long long b){
    return a / gcd(a,b)*b;
}

int main(){


    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin>>p[i];
        --p[i]; 
    }

    vector<bool> visited(n, false);
    long long ans = 1;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            int cnt=0, j=i;
            while(!visited[j]){
                visited[j]=true;
                j=p[j];
                cnt++;
            }
            ans = lcm(ans,cnt)%MOD;
        }
    }

    cout<<ans<<endl;
    return 0;
}
