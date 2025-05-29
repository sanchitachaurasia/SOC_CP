#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin>>n;

    long long S = n*(n+1)/2;

    if(S%2!=0) {
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";

    long long half = S/2;
    vector<int> set1, set2;

    for(int i=n; i>=1; i--) {
        if(i<=half){
            set1.push_back(i);
            half -= i;
        }else{
            set2.push_back(i);
        }
    }

    cout<<set1.size()<<endl;
    for (int x : set1) cout<<x<<" ";
    cout<<endl ;

    cout<<set2.size()<<endl;
    for(int x : set2) cout<<x<<" ";
    cout<<endl;

    return 0;
}
