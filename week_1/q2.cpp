#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class hey{        //x is the row no and y is the column no
    public:
    int first1(int x){
        if(x==1){
                return 1;
            }
        if(x%2==0){
            return first1(x-2)+(x-1)*4;
        }
        else{
            return first1(x-1)+1;
        }
    }
    int first2(int y){
        if(y==1){
                return 1;
            }
        if(y%2!=0){
            return first2(y-2)+(y-1)*4;
        }
        if(y%2==0){
            return first2(y-1)+1;
        }
    }
    int number(int x,int y){
        
        if(max(x,y)==x){
            return first1(x)+y-1;
        }
        if(max(x,y)==y){
            return first2(y)+x-1;
        }
    }
    
};
int main(){
    
    int t;
    hey find1;
    cin>>t;
    vector<int>v;
    for(int i=0;i<t;i++){
        int x;
        int y;
        cin>>x>>y;
        v.push_back(find1.number(x,y));
    }
    for(int i:v){
        cout<<i<<endl;
    }
}