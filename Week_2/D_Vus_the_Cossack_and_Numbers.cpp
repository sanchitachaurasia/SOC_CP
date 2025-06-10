#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
cin>>n;
double a[n];
for(int i=0;i<n;i++){
    cin>>a[i];

}
int b[n];
long long int sum=0;
for(int i=0;i<n;i++){
    b[i]=floor(a[i]);
    sum+=b[i];

}
sum*=(-1);
int k=0;
for(int i=0;i<n;i++){
    if(b[i]!=a[i]&&k<sum){
        b[i]++;
        k++;
    }
    cout<<b[i]<<" ";
}cout<<endl;


}