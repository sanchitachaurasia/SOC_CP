class Solution {
    //1D DP 
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> ispal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 1 || len == 2) {
                        ispal[i][j] = true;
                    } else {
                        ispal[i][j] = ispal[i + 1][j - 1];
                    }
                }
            }
        }
        vector<int>dp(n,INT_MAX);
        for(int i=0;i<s.size();i++){
            if(ispal[0][i]) dp[i]=0;
            else {
                for(int j=1;j<=i;j++){
                    if(ispal[j][i]){
                        dp[i]=min(dp[i], dp[j-1]+1);
                    }
                }
            }
        }       
        return dp[n-1];
    }
};
