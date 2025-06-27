#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll get_beauty(vector<vector<int>>& mat,int x1,int y1,int size){
    if (size==1) return mat[x1][y1];

    int half = size / 2;
    ll max_val = 0;

    for(int i=x1; i<x1+size; i++){
        for (int j=y1; j<y1+size; j++){
            max_val = max(max_val, (ll)mat[i][j]);
        }
    }

    ll total = max_val;
    total += get_beauty(mat, x1, y1, half); 
    total += get_beauty(mat, x1, y1 + half, half); 
    total += get_beauty(mat, x1 + half, y1, half); 
    total += get_beauty(mat, x1 + half, y1 + half, half); 
    return total;
}

int main(){
    int total;
    cin>>total;
    int n = 0;
    int t = total;
    while(t%4==0){
        t/=4;
        n++;
    }

    int dim=1<<n;
    vector<vector<int>> mat(dim, vector<int>(dim));

    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            int x;
            cin >> x;
            mat[i][j] = x;
        }
    }

    cout<<get_beauty(mat,0,0,dim)<<endl;
    return 0;
}
