#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long int> duration(n);
    vector<long long int> deadline(n);
    for(int i = 0; i < n; ++i){
        cin >> duration[i] >> deadline[i];
    }
    sort(duration.begin(), duration.end());
    long long count = 0;
    for(int i = 0; i < n; ++i){
        count += deadline[i]; 
        count -= ((n - i) * duration[i]);
    }
    cout << count << endl;
}
