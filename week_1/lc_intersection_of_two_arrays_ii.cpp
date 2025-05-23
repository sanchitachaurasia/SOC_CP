class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(begin(nums1), end(nums1)); sort(begin(nums2), end(nums2));
        set_intersection(cbegin(nums1), cend(nums1), cbegin(nums2), cend(nums2), back_inserter(result));
        return result;
    }
};
