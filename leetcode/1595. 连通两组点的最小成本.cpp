// 待理解
class Solution {
public:
    int INF=1e9;
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n=cost.size(),m=cost[0].size();
        vector<vector<int>>dp(n+1,vector<int>(1<<m,INF));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<1<<m;j++){
                for(int k=0;k<m;k++){
                    //dp[i-1][j]从上一行转移过来,dp[i][j]从当前行转移过来
                   dp[i][j|(1<<k)]=min(dp[i][j|(1<<k)],min(dp[i-1][j],dp[i][j])+cost[i-1][k]);
                }
            }
        }
        return dp[n][(1<<m)-1];
    }
};
