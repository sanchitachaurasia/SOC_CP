#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lengthOfSubStrings;
        for(int i=0;i<s.length();++i){
            bool found=false;
            bool complete=false;
            for(int j=i+1;j<s.length();++j){
                for(int p=i;p<=j-1;++p){
                    if(s[p]==s[j]){
                        found=true;
                    }
                    if(j==s.length()-1){complete=true;}
                }
                if(found){lengthOfSubStrings.push_back(j-i);
                break;}
                if(complete){lengthOfSubStrings.push_back(j-i+1);}
            }
        }
            auto ans= max_element(lengthOfSubStrings.begin(),lengthOfSubStrings.end());
            return *ans;
    }
};
