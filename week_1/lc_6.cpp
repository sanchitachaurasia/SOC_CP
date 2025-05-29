#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        
        unordered_map<char, int> p_freq;
        unordered_map<char, int> window_freq;
        
        for (int i = 0; i < p.size(); i++) {
            p_freq[p[i]]++;
            window_freq[s[i]]++;
        }
        
        vector<int> ans;
        
        if (p_freq == window_freq) {
            ans.push_back(0);
        }
        
        for (int i = 0; i < s.size() - p.size(); i++) {
            window_freq[s[i]]--;
            if (window_freq[s[i]] == 0) {
                window_freq.erase(s[i]);
            }
            window_freq[s[i + p.size()]]++;
            if (p_freq == window_freq) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
