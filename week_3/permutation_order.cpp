#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;
const int MAXN = 21;

ll fact[MAXN];

void compute_factorials(){
    fact[0] =1;
    for(int i=1; i<MAXN; i++)
        fact[i] = fact[i-1]*i;
}

int main(){

    compute_factorials();

    int t;
    cin>>t;

    while(t--){
        int type,n;
        cin>>type>>n;

        if(type==1){
            ll k;
            cin>>k;
            vector<int> nums;
            for(int i=1; i<=n; i++) nums.push_back(i);

            --k; 

            vector<int> res;
            for(int i=n; i>=1; i--){
                ll idx = k / fact[i - 1];
                res.push_back(nums[idx]);
                nums.erase(nums.begin() + idx);
                k%= fact[i-1];
            }

            for(int x:res) cout<<x<<' ';
            cout<<endl;

        }
        else if(type==2){
            vector<int> perm(n);
            for(int i=0; i<n; i++)
                cin>>perm[i];

            vector<int> nums;
            for(int i=1; i<=n; i++) nums.push_back(i);

            ll rank = 1;
            for(int i=0; i<n; i++){
                int pos =find(nums.begin(),nums.end(),perm[i])-nums.begin();
                rank+=pos*fact[n-i-1];
                nums.erase(nums.begin()+pos);
            }
            cout<<rank<<endl;
        }
    }

    return 0;
}
