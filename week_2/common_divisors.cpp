#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {

    int q;
    cin>>q;

    while(q--){
        int n;
        cin>>n;

        vector<int> sticks(4*n);

        for(int i=0; i<4*n; i++){
            cin>>sticks[i];
        }

        sort(sticks.begin(), sticks.end());

        bool possible = true;

        // Step 1: Check if all sticks can be paired
        for(int i=0; i<4*n; i+=2){
            if(sticks[i]!=sticks[i+1]){
                possible = false;
                break;
            }
        }

        if(!possible){
            cout<<"NO\n";
            continue;
        }

        // Step 2: Check if all rectangles can have the same area
        int left = 0;
        int right = 4*n-1;
        int area = sticks[left]*sticks[right];

        while(left<right){
            int a = sticks[left];
            int b = sticks[right];
            if(sticks[left]!=sticks[left+1] || sticks[right]!=sticks[right-1] || a*b!=area){
                possible = false;
                break;
            }
            left += 2;
            right -= 2;
        }

        if(possible) cout<<"YES\n";
        else  cout<<"NO\n";
    }

    return 0;
}
