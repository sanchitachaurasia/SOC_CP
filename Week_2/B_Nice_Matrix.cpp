#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n, m;
        cin >> n >> m;
        long long int array[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> array[i][j];
            }
        }
        long long int steps=0;
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < (m + 1) / 2; j++)
            {
                long long int nums[4] = {
                    array[i][j], array[i][m - j-1], array[n - i-1][j], array[n - i-1][m - j-1]};
               sort(nums,nums+4);
                if(n-i-1==i&&m-j-1==j){

                }
                else if(n-i-1==i||m-j-1==j){
                   steps+=((nums[3]+nums[2]-nums[1]-nums[0])/2);
                }
                else{steps+=(nums[3]+nums[2]-nums[1]-nums[0]);}}

        }
        cout<<steps<<"\n";
    }
}
