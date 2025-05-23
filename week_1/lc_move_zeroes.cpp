class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size(); 
        vector<int>vec;
        for(int i=0; i<n;i++){
            if(nums[i]==0){
                vec.push_back(i);
                }
            }     
        for(int j=vec.size()-1;j>=0;j--){
            nums.erase(nums.begin()+vec[j]);
        }
        for(int i=0;i<vec.size();i++){
            nums.push_back(0);
        }
    }
};
