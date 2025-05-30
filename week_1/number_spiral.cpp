#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    while(n--){
        long long y,x;
        cin>>y>>x;

        long long m = max(y,x);
        long long result;

        if(m%2==0) {
            if(y==m)
                result = m*m-x+1;
            else
                result = (m-1)*(m-1)+y;
        }else{
            if(x==m)
                result = m*m-y+1;
            else
                result = (m-1)*(m-1)+x;
        }

        cout<<result<<endl;
    }
     return 0;
}
