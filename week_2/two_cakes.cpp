#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> arr(2*n);
    for(int i=0; i<2*n; i++){
        cin>>arr[i];
    }

    vector<pair<int,int>> positions(n+1); // 1-based indexing

    for(int i=0; i<2*n; i++){
        int val = arr[i];
        if(positions[val].first == 0 && val!=arr[0]){
            positions[val].first = i;
        }
        else{
            positions[val].second = i;
        }
    }

    int sasha_pos = 0;
    int dima_pos = 0;
    long long total_distance = 0;

    for(int i=1; i<=n; i++){
        int p1 = positions[i].first;
        int p2 = positions[i].second;

        int option1 = abs(sasha_pos-p1) + abs(dima_pos-p2);
        int option2 = abs(sasha_pos-p2) + abs(dima_pos-p1);

        if(option1<=option2){
            total_distance+=option1;
            sasha_pos = p1;
            dima_pos = p2;
        }else{
            total_distance+=option2;
            sasha_pos = p2;
            dima_pos = p1;
        }
    }

    cout<<total_distance<<'\n';
    return 0;
}