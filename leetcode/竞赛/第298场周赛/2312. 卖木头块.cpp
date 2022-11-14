// ###################################################### 版本1 ###################################################### //
// dp，时间复杂度O(n^3)
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        for(auto p : prices){
            int h = p[0], w = p[1], v = p[2];
            dp[h][w] = v;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k < i; k++){
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
                for(int l = 1; l < j; l++){
                    dp[i][j] = max(dp[i][j], dp[i][l] + dp[i][j - l]);
                }
            }
        }
        return dp[m][n];
    }
};