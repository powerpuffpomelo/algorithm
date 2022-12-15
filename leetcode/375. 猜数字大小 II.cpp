// ###################################################### 版本1 ###################################################### //
// 区间dp
class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> dp;
    int getMoneyAmount(int n) {
        dp = vector<vector<int>>(n + 2, vector<int>(n + 2));
        for(int len = 2; len <= n; len++){
            for(int i = 1; i + len - 1 <= n; i++){
                int j = i + len - 1;
                dp[i][j] = INF;
                for(int k = i; k <= j; k++){
                    dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
                }
            }
        }
        return dp[1][n];
    }
};