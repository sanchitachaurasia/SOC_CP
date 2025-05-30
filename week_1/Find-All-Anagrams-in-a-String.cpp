#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char,int> checked2;
        for(int m=0;m<p.size();++m){
                checked2[p[m]]++;
            }
            if(s.size()>=p.size()){
        for(int i=0;i<=s.size()-p.size();++i){
            map<char,int> checked1;
            for(int m=i;m<i+p.size();++m){
                checked1[s[m]]++;
            }
            if(checked1==checked2){ans.push_back(i);}
        }}
        return ans;
    }
};
