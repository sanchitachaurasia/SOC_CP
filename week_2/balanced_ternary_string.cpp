 #include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    vector<int> cnt(3, 0);
    for(char c : s){
        cnt[c-'0']++;
    }

    int target = n/3;

    for(int i =0; i<n; i++){
        int d = s[i]-'0';

        if(cnt[d]>target){
            if(d==2 && cnt[0]<target){
                s[i]='0';
                cnt[2]--; cnt[0]++;
            }
            else if(d==2 && cnt[1]<target){
                s[i]='1';
                cnt[2]--; cnt[1]++;
            }
            else if(d==1 && cnt[0]<target){
                s[i]='0';
                cnt[1]--; cnt[0]++;
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        int d = s[i] - '0';

        if(cnt[d]>target){
            if(d==0 && cnt[2]<target){
                s[i]='2';
                cnt[0]--; cnt[2]++;
            }
            else if(d==0 && cnt[1]<target){
                s[i]='1';
                cnt[0]--; cnt[1]++;
            }
            else if(d==1 && cnt[2]<target){
                s[i]='2';
                cnt[1]--; cnt[2]++;
            }
        }
    }

    cout<<s<<endl;
    return 0;
}
