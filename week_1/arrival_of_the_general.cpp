#include<iostream>
#include<vector>
using namespace std;
int main() {
    
    int n;
    cin >> n;

    vector<int> arr(n);
    
    
    int max_height = -1, min_height = 101;
    int max_index = -1, min_index = -1;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        
        if(arr[i]>max_height) {
            max_height = arr[i];
            max_index = i;
        }
        
        if(arr[i] <= min_height) {
            min_height = arr[i];
            min_index = i;
        }
    }

    int swap = max_index + (n-1-min_index);
    if(min_index<max_index) swap-=1;

    cout<<swap<<endl;
}
