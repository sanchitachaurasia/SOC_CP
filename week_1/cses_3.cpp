#include <iostream>
using namespace std;
 
int main(){
    string given;
    cin>>given;
    int len;
    len = given.length();
    int semi_ans = 1;
    int ans = 1;
    for (int i = 0; i < len - 1; i++)
    {
        if (given[i] == given[i+1])
        {
            semi_ans += 1;
        }
        else{
            if (ans < semi_ans)
            {
                ans = semi_ans;
            }
            semi_ans = 1;
        }
    }
    if (ans < semi_ans)
    {
        ans = semi_ans;
    }
    cout<< ans;
}