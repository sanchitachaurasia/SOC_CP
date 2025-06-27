#include <iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<tuple<int, int, int>> ranges(n);
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        ranges[i] = {x,y,i};
    }

    sort(ranges.begin(),ranges.end(), [](auto &a, auto &b) {
        if(get<0>(a)==get<0>(b))
            return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    vector<int> contains(n), contained(n);
    
    int max_r = 0;
    for(auto &[l,r,idx]:ranges){
        if (r <= max_r) contained[idx] = 1;
        max_r = max(max_r,r);
    }

    int min_r = 1e9 + 1;
    for(int i=n-1; i>=0; i--){
        auto [l, r, idx] = ranges[i];
        if (r>=min_r) contains[idx] = 1;
        min_r = min(min_r,r);
    }

    for(int x:contains) cout<<x<<' ';
    cout<<endl;
    for(int x:contained) cout<<x<<' ';
    cout<<endl;
    return 0;
}
