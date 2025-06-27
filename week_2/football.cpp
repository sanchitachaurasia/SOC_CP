#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    vector<long long> results;
    results.reserve(t);

    while(t--){
        long long N;
        cin>>N;

        long long chanek = 0;
        bool isChanekTurn = true;

        while(N>0){
            long long take;
            
            if(N%2==0)  take = N/2;
            else   take=1;

            if(isChanekTurn)  chanek+=take;
            
            N-=take;
            isChanekTurn=!isChanekTurn;
        }

        results.push_back(chanek);
    }

    for(long long r : results)    cout <<r<<endl;

    return 0;
}
