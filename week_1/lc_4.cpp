#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);
        unordered_multiset<int> ins;
        for(int i = 0; i < nums1.size(); i++){
            ins.insert(nums1[i]);
        }

        vector<int> ans;
        for(int i = 0; i < nums2.size(); i++){
            if(ins.find(nums2[i]) != ins.end()) { //present inside
                ins.erase(ins.find(nums2[i]));
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};