#include<bits/stdc++.h>
using namespace std;

int main() {
    int mat[5][5];
    int x, y, moves=0;

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    }

    if (x==0 || x==4) moves+=2;
    else if (x==1 || x==3) moves++;

    if (y==0 || y==4) moves+=2;
    else if (y==1 || y==3) moves++;

    cout << moves;
}