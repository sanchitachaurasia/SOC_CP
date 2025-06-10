#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, l, r;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<int> vals;
    for (int i = 0; i < n+1; i++)
    {
       vals.push_back(0);
    }

    for (int i = 0; i < q; i++)
    {
        cin >> l;
        cin >> r;
        vals[l - 1]++;
        vals[r]--;
    }
    vals.pop_back();
    for (int i = 1; i < n; i++)
    {
        vals[i] += vals[i - 1];
    }
    sort(vals.begin(), vals.end());
    long long int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum +=
            ((long long int)(vals[i])) * nums[i];
    }
    cout << sum << endl;
}
