#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<double> a(n);
    vector<int> b(n);
    vector<int> candidates;

    int floor_sum = 0;

    for(int i=0; i<n; i++){
        cin>>a[i];
        int fl =floor(a[i]);
        b[i] = fl;
        floor_sum+=fl;

        if(abs(a[i]-fl)>1e-8){
            candidates.push_back(i);
        }
    }

    int need_ceil=-floor_sum;
    for(int i=0; i<need_ceil; i++){
        b[candidates[i]]+=1; 
    }

    for(int i=0; i<n; i++){
        cout<<b[i]<<endl;
    }

    return 0;
}
