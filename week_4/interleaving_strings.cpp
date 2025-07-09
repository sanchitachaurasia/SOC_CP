class Solution {
public:
//2D DP
    bool what(string & s1, string &s2, string &s3, int i,int j, vector<vector<int>> &memo){
        if(memo[i][j]!=-1) return memo[i][j];
        if(i==s1.size() && j==s2.size() && i+j==s3.size()) return true;
        int m=s1.size(), n=s2.size();
        int k=i+j;
        //what if next element of s3 matches next of s1?
        bool a= (i<m && s1[i]==s3[k]) && what(s1,s2,s3,i+1,j,memo);
        //for s2 
        bool b= (j<n && s2[j]==s3[k]) && what(s1,s2,s3,i,j+1,memo);
        return memo[i][j]=a||b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        int n=s1.size(), m=s2.size();
        vector<vector<int>> memo(n+1, vector<int> (m+1,-1));
        return what(s1,s2,s3,0,0,memo);
    }
};
