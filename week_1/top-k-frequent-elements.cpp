#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> data;
        for(int i=0;i<nums.size();++i){
            data[nums[i]]++;
        } 
        vector<int> ans(k);
        std::vector<std::pair<int, int>> vec(data.begin(),data.end());
          std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    for(int i=0;i<k;++i){
        ans.push_back(vec[i].first);
    }
    }
};
