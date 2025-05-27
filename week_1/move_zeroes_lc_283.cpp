class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // positions of the zeros in inc order
        vector<int> zeros = {};
        for(int i = 0; i < nums.size(); i++) {
            if (!nums[i])
                zeros.push_back(i);
        }
        // hack to prevent checking for final zero separetely
        zeros.push_back(nums.size());

        // using two pointers - both running together - O(n)
        // j keeps track of how many zeros we have passed
        // zeros[j] hols their positions which act as limits for i
        // i is pointer moving in nums
        // NOTE: on termination of inner loop the j-th zero reaches
        // zeros[j+1]-1 position
        int i;
        for(int j = 0; j < zeros.size() - 1; j++) {
            for(i = zeros[j] + 1; i < zeros[j+1]; i++)
                swap(nums[i], nums[i - j - 1]);
        }
    }
};