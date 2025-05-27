class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        vector<int> ans;
        sort(nums2.begin(),nums2.end());
        int v=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=v;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    v=j+1;
                    ans.push_back(nums1[i]);
                    break;
                }

            }
        }
        return ans;
       
    }
};