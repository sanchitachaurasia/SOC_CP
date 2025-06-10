#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll modDistanceFromMedian(ll a, ll b, ll c, ll d) {
    vector<ll> nums = {a, b, c, d};
    sort(nums.begin(), nums.end());
    ll median = nums[1];
    ll sum = 0;
    for (ll num : nums) {
        sum += abs(num - median);
    }
    return sum;
}
 
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> given(n, vector<ll>(m));
        for(ll i = 0; i < n; ++i){
            for(ll j = 0; j < m; ++j){
                cin >> given[i][j];
            }
        }
 
        ll k = 0;
        for(ll i = 0; i < n / 2; ++i){
            for(ll j = 0; j < m / 2; ++j){
                k += modDistanceFromMedian(given[i][m - j - 1], given[n - 1 - i][m - 1 - j], given[i][j], given[n - i - 1][j]);
            }
        }
 
        if(n % 2 == 1){
            ll row = n / 2;
            for(ll j = 0; j < m / 2; ++j){
                k += abs(given[row][j] - given[row][m - 1 - j]);
            }
        }
 
        if(m % 2 == 1){
            ll col = m / 2;
            for(ll i = 0; i < n / 2; ++i){
                k += abs(given[i][col] - given[n - 1 - i][col]);
            }
        }
 
        cout << k << endl;
    }
}
