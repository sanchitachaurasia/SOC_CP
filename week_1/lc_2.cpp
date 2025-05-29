#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int pointer = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            swap(nums[pointer], nums[i]);
            pointer++;
        }
    }
}
