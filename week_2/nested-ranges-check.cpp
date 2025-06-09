#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> given(n);
    vector<int> contains(n),contained(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> get<0>(given[i]) >> get<1>(given[i]);
        get<2>(given[i]) = i;
    }
    sort(given.begin(), given.end(), [](const auto &a, const auto &b)
         {
    if (get<0>(a) == get<0>(b)) {
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) > get<0>(b); });
    int min_y=1e9+1;
    for (auto &t:given)
    {
        if(min_y<=get<1>(t)){contains[get<2>(t)]=1;}
        min_y=min(min_y,get<1>(t));
    }
    sort(given.begin(),given.end(),[](const auto &a,const auto &b){
        if(get<1>(a)!=get<1>(b))return get<1>(a)>get<1>(b);
        return get<0>(a)<get<0>(b);
    });
    int min_x=1e9+1;
    for(auto &t:given){
        if(min_x<=get<0>(t))contained[get<2>(t)]=1;
        min_x=min(min_x,get<0>(t));
    }
    for(auto x:contains){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x:contained){
        cout<<x<<" ";
    }
    cout<<endl;
}
