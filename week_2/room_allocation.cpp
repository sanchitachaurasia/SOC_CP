#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Customer {
    int a, b, idx;
};

int main() {

    int n;
    cin>>n;
    vector<Customer> customers(n);
    for (int i=0; i<n; i++){
        cin>>customers[i].a>>customers[i].b;
        customers[i].idx=i;
    }

    sort(customers.begin(),customers.end(),[](Customer &x, Customer &y){
        return x.a<y.a;
    });

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    vector<int> ans(n);
    int room_count = 0;

    for(auto &cust : customers){
        if(!pq.empty() && pq.top().first<cust.a){
            int room = pq.top().second;
            pq.pop();
            ans[cust.idx]=room;
            pq.emplace(cust.b,room);
        }
        else{
            ++room_count;
            ans[cust.idx]=room_count;
            pq.emplace(cust.b, room_count);
        }
    }

    cout<<room_count<<endl;
    for(int r:ans) cout<<r<<endl;
    cout<<endl;

    return 0;
}
