#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> snum1;
        map<int,int> snum2;
        for(int i=0;i<nums1.size();++i){
            snum1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();++i){
            snum2[nums2[i]]++;
        }
        for(auto x:snum1){
            for(auto y:snum2){
                if(x.first==y.first&&x.second>y.second){for(int m=0;m<y.second;++m){ans.push_back(x.first);}}
                if(x.first==y.first&&x.second<=y.second){for(int m=0;m<x.second;++m){ans.push_back(x.first);}}
            }
        }
        return ans;
    }
};
