#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,q;
    cin>>n>>q;

    vector<long long> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    vector<int> freq(n+1,0); 

    for(int i=0; i<q; i++){
        int l,r;
        cin>>l>>r;
        freq[l-1]+=1;
        freq[r]-=1;
    }

    for(int i=1; i<n; i++){
        freq[i]+= freq[i-1];
    }
    freq.pop_back(); 
    sort(a.begin(), a.end());
    sort(freq.begin(), freq.end());

    long long result = 0;
    for(int i=0; i<n; i++){
        result+=a[i]*1LL*freq[i];
    }

    cout<<result<<endl;
    return 0;
}
