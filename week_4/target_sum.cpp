class Solution {
public:
//backtrack?
    int backtrack(vector<int>&nums, int currsum, int target, int index){
        if( index== nums.size()) return currsum==target ? 1:0;

        //add
        int add= backtrack(nums, currsum+nums[index], target,index+1);
        //subtract or backtrack the add step- coz we are going back to currsum-nums[index] by subtracting it.
        int sub=backtrack(nums,currsum-nums[index],target, index+1);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums, 0,target,0);
    }
};
