//dp[i][j][1/0] 第i天结束的时候，已经完整地完成了j比交易，当前持有1不持有0股票，最大利润
//dp[i][j][1] = max(dp[i - 1][j][0] - prices[i], dp[i - 1][j][1]);
//dp[i][j][0] = max(dp[i - 1][j - 1][1] + prices[i], dp[i - 1][j][0]);
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1010)));

        int ans = 0;
        dp[0][0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j][1] = max(dp[i - 1][j][0] - prices[i - 1], dp[i - 1][j][1]);
                dp[i][j][0] = dp[i - 1][j][0];
                if(j) dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + prices[i - 1]);
                ans = max(ans, dp[i][j][0]);
            }
        }
        return ans;
    }
};