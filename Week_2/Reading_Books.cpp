#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()

int main() {
    fastio();
    int n;
    cin>>n;

vi store(n);
ll t;
ll sum=0;

for(int i=0;i<n;i++){
    cin>>store[i];
   
}
sort(all(store));
reverse(all(store));
for(int i =0;i<n;i++){
    sum+=store[i];
}
t=(sum/2>store[0])?sum:2*store[0];



    cout<<t;
}