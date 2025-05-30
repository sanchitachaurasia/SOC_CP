#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        map<int,int> sorted;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){sorted.insert({i,count});
        count++;}
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
            nums[sorted[i]]=nums[i];}
        }
        for(int i=count;i<nums.size();++i){
            nums[i]=0;
        }
    }
};
