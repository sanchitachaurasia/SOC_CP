#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix(5, vector<int>(5, 0));
    int x = 0;
    int y = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1){
                x = i;
                y = j;
            }
        }
    }
    int ans = abs(x - 2) + abs(y - 2);
    cout << ans;
}