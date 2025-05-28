#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        visited[nums[0]] = 1;
        for(int i = 1; i < nums.size(); i++){
            if (visited[target - nums[i]] != 0){
                vector<int> ans;
                ans.push_back(visited[target - nums[i]] - 1);
                ans.push_back(i);
                return ans;
            }

            else{
                visited[nums[i]] = i+1;
            }
        }
    }
};

int main(){
    return 0;
}