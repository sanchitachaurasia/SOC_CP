
#include<iostream>
#include<vector>
using namespace std;
long long int k=0;
void proceed(long long int &N){
    if(N%4==0){
        k+=1;
        k+=(N-2)/2;
        N=(N-2)/2-1;
    }
    else if(N%4==1){
        k+=2;
        N=(N-3)/2;
    }
    else if(N%4==2){
        k+=N/2;
        N=N/2-1;
    }
    else{
        k+=1;
        N=(N-1)/2;
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        long long int N;
        cin>>N;
        k=0;
        for(;N>5;){
            proceed(N);
        }
        if(N==5){k+=2;}
        if(N==4){k+=3;}
        if(N==3){k+=2;}
        if(N==2){k+=1;}
        if(N==1){k+=1;}
        cout<<k<<endl;
    }
}
