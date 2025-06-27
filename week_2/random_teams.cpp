#include<iostream>
using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;

    long long max_team_size = n-m+1;
    long long kmax = max_team_size*(max_team_size-1)/2;

    long long q = n/m;
    long long r = n%m;
    long long kmin = r*(q+1)*q/2 + (m-r)*q*(q-1)/2;

    cout<<kmin<<" "<<kmax<<"\n";
    return 0;
}
