#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(){
    vector<vector<int>> A(5, vector<int>(5));
    int m,n;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            cin>>(A[i])[j];
            if(A[i][j]==1){m=i;n=j;}
        }
    }
    cout<<(abs(m-2)+abs(n-2))<<endl;
}
