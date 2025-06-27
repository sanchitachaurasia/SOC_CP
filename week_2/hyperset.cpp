#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>a[i][j];

        long long ans = 0;

        for(int i=0; i<(n+1)/2; i++){
            for(int j=0; j<(m+1)/2; j++) {
                // collect symmetric positions
                vector<int> vals;
                // set of unique valid symmetric coordinates
                set<pair<int, int>> coords={{i,j}, {n-i-1,j}, {i,m-j-1}, {n-i-1,m-j-1}};

                for(auto [x,y] : coords){
                    vals.push_back(a[x][y]);
                }

                sort(vals.begin(), vals.end());
                int median = vals[vals.size()/2];
                for(int val : vals)
                    ans+=abs(val-median);
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
