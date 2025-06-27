#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<long long,long long>> tasks(n);
    for(int i=0; i<n; i++)  cin>>tasks[i].first>>tasks[i].second; 

    sort(tasks.begin(),tasks.end());

    long long cur_time = 0;
    long long total_reward = 0;

    for(auto& [duration,deadline] : tasks){
        cur_time+=duration;
        total_reward+=(deadline-cur_time);
    }

    cout<<total_reward<<endl;
    return 0;
}
