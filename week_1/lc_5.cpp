#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for(int i = 0; i < nums.size(); i++){
            freq_map[nums[i]]++;
        }

        vector<int> top_ks(1e5+5, 0);
        vector<int> freq_to_nums[1e5+5];

        for(const auto& [num, freq] : freq_map){
            top_ks[freq]++;
            freq_to_nums[freq].push_back(num);
        }

        vector<int> freq_to_select;

        for(int i = 1e5+4; i >=0; i--){
            if(top_ks[i] > 0 && k > 0){
                freq_to_select.push_back(i);
                k = k - top_ks[i];
            }
        }

        vector<int> ans;

        for(int freq : freq_to_select){
            for(int i = 0; i < freq_to_nums[freq].size(); i++){
                ans.push_back(freq_to_nums[i]);
            }
        }

        return ans;

    }
};