class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n=prices.size();
        //3D DP: i=day, j= transactions, k=hold/not hold
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3,vector<int>(2,0)));
        dp[0][1][0]=0;
        dp[0][1][1]=-prices[0];
        dp[0][2][0]=0;
        dp[0][2][1]=-prices[0];
        for(int i=1;i<n;i++){
            for(int j=1;j<=2;j++){
                dp[i][j][0]= max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]); //do nothing or sell
                dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]); //hold stack or buy(current profit- price of this stack) : transaction--
            }
        }
        return dp[n-1][2][0];
    }
};
