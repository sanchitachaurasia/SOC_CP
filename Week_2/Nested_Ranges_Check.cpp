#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ranges;
    vector<int> a(n, 0);
    vector<int> b(n, 0);

    for (int i = 0; i < n; i++)
    {
        int ac, bc;
        cin >> ac >> bc;
        ranges.push_back({ac, bc, i});
    }
    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b)
         {
        if(get<0>(a)==get<0>(b)){
            return get<1>(a)>get<1>(b);
        }return get<0>(a)<get<0>(b); });

    int right = 0;

    for (auto [l, r, i] : ranges)
    {
        if (right >= r)
        {

            b[i] = 1;
        }
        else
        {
            right = r;
        }
    }
    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b)
         {
        if(get<1>(a)==get<1>(b)){
            return get<0>(a)>get<0>(b);
        }return get<1>(a)<get<1>(b); });
    int left = 0;
    for (auto [l, r, i] : ranges)
    {
        if (left >= l)
        {

            a[i] = 1;
        }
        else
        {
            left = l;
        }
    }
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : b)
    {
        cout << i << " ";
    }
}