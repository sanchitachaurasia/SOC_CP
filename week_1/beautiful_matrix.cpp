#include<iostream>
using namespace std;
 
int main(){
 
    int element, row, col;
    
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            cin>>element;
            if(element==1){
                row=i, col=j;
            }
        }
    }
    
    cout<<abs(row-3)+abs(col-3)<<endl;
    
}
