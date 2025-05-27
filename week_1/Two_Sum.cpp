#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> x;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && nums[i] + nums[j] == target)
                {
                    x.push_back(i);
                    x.push_back(j);
                    return x;
                }
            }
        }
        return {};
    }
};
