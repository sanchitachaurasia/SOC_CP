class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n=word1.size(), m=word2.size();
        vector<vector<int>> dist(n+1,vector<int>(m+1,0));
        for (int i = 0; i <= n; i++) dist[i][0] = i;
        for (int j = 0; j <= m; j++) dist[0][j] = j;
        for(int i=1; i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dist[i][j]=dist[i-1][j-1];
                }
                else{
                    dist[i][j]=min({dist[i-1][j-1], dist[i-1][j],dist[i][j-1]}) +1;
                }
            }
        }

        return dist[n][m];
    }
};
