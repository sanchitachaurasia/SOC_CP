class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> sort;
        unordered_map<int, int> store;
        vector<int> ans;
        
        for (int i : nums) {
            store[i]++;
        }
        for (auto& element : store) {
            sort.push_back(element);
        } 
        int n = sort.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (sort[j + 1].second > sort[j].second){
                    swap(sort[j],sort[j+1]);
                }
            }
        }
       
        for (int i = 0; i < k; i++) {
            ans.push_back(sort[i].first);
        }

        return ans;
    }
};