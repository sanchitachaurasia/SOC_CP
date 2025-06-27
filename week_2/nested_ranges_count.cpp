#include <bits/stdc++.h>
using namespace std;

struct Range {
    int l,r,idx;
};

class FenwickTree {
public:
    vector<int> bit;
    int n;

    FenwickTree(int size) {
        n=size+2;
        bit.assign(n, 0);
    }

    void update(int i, int delta){
        for(++i; i<n; i+=i & -i)
            bit[i]+=delta;
    }

    int query(int i){
        int res = 0;
        for (++i;i>0;i-=i & -i)
            res+=bit[i];
        return res;
    }

    int query(int l,int r) {
        return query(r)- query(l-1);
    }
};

int main(){
    int n;
    cin>>n;
    vector<Range> ranges(n);
    vector<int> all_coords;

    for(int i=0; i<n; i++){
        cin>>ranges[i].l>>ranges[i].r;
        ranges[i].idx=i;
        all_coords.push_back(ranges[i].r);
    }

    sort(all_coords.begin(),all_coords.end());
    all_coords.erase(unique(all_coords.begin(),all_coords.end()),all_coords.end());
    auto compress=[&](int x){
        return lower_bound(all_coords.begin(),all_coords.end(),x)-all_coords.begin();
    };

    sort(ranges.begin(),ranges.end(),[](const Range &a, const Range &b){
        if(a.l==b.l) return a.r > b.r;  
        return a.l < b.l;
    });

    FenwickTree bit1(all_coords.size());
    vector<int> contains(n);
    for(int i=n-1; i>=0; i--){
        int pos = compress(ranges[i].r);
        contains[ranges[i].idx]=bit1.query(pos);
        bit1.update(pos, 1);
    }

    sort(ranges.begin(),ranges.end(),[](const Range &a, const Range &b){
        if(a.l==b.l) return a.r<b.r;
        return a.l < b.l;
    });

    FenwickTree bit2(all_coords.size());
    vector<int> contained_by(n);
    for(int i=0; i<n; i++){
        int pos = compress(ranges[i].r);
        contained_by[ranges[i].idx]=bit2.query(pos, all_coords.size()-1);
        bit2.update(pos, 1);
    }

    for(int x:contains) cout<<x<<" ";
    cout<<endl;
    for(int x:contained_by) cout<<x<<" ";
    cout<<endl;

    return 0;
}
