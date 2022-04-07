// ###################################################### 版本1 ###################################################### //
// dp, dp[i][j]代表，仅使用前i个piles，从中取出j枚硬币的最大价值
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        vector<vector<int>> sum;
        sum = piles;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < sum[i].size(); j++) sum[i][j] += sum[i][j - 1];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++){
                for(int x = 0; x <= min(j, (int)sum[i - 1].size()); x++){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + (x ? sum[i - 1][x - 1] : 0));
                }
            }
        }
        return dp[n][k];
    }
};
