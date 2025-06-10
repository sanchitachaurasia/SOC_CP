#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> cust;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cust.push_back({a, b, i});
    }
    sort(cust.begin(), cust.end(), [](auto &a, auto &b)
         {
        if(get<0>(a)==get<0>(b)){
            return get<1>(a)>get<1>(b);
        }
        return get<0>(a)<get<0>(b); });
    vector<tuple<int, int, int>> abc;

    for (int i = 0; i < n; i++)
    {
        int s = get<0>(cust[i]);
        int x = get<2>(cust[i]);
        abc.push_back({s, -1, x});
         s = get<1>(cust[i]);
        abc.push_back({s, 1, x});
    }
    int num=0;
    queue<int>room;
    vector<int>allocation(n);


    sort(abc.begin(),abc.end());
    unordered_map<int,int> lastemp;
    for(auto[s,i,x]:abc){
        if(i<0){
            if(room.size()==0||s<=lastemp[room.front()]){
                allocation[x]=++num;

            }
            else{
               allocation[x]= room.front();
               room.pop();
            }
        }
        else{
            lastemp[allocation[x]]=s;

            room.push(allocation[x]);
        }
    }
    cout<<num<<"\n";
    for(int i:allocation){
        cout<<i<<" ";
    }

}