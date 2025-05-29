#include <iostream>
using namespace std;
 
int main(int argc, char const *argv[])
{
    long long int n;
    cin>>n;
    if (n%4 == 3 || n%4 == 0)
    {   
        cout<< "YES"<< endl;
        long long int set1[n];
        long long int set2[n];
 
        for (long long int i = 0; i < n; i++)
        {
            set1[i] = 0;
            set2[i] = 0;
        }
 
        long long int arr_sum_1 = 0;
        long long int arr_sum_2 = 0;
 
 
        for (long long int i = n; i > 0; i--)
        {   
            if (arr_sum_1 <= arr_sum_2)
            {
                set1[i-1] = i;
                arr_sum_1+=i;
            }
            else {
                set2[i-1] = i;
                arr_sum_2+=i;
            }
            
        }
        
 
            long long int ans1 = 0;
            long long int ans2 = 0;
            for (long long int j = 0; j < n; j++)
            {
                if (set1[j] != 0)
                {
                    ans1+=1;
                }
                if (set2[j] != 0)
                {
                    ans2+=1;
                }
            }
 
 
            cout<< ans1<< endl;
            for (long long int j = 0; j < n; j++)
            {
                if (set1[j] != 0)
                {
                    cout<<set1[j]<<" ";
                }
                
            }
            cout<< endl<<ans2<<endl;
            for (long long int j = 0; j < n; j++)
            {
                if (set2[j] != 0)
                {
                    cout<<set2[j]<<" ";
                }
                
            }
    }
    else {
        cout<< "NO";
    }
    
    return 0;
}
