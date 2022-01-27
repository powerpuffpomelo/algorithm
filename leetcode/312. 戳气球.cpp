// ###################################################### 版本1 ###################################################### //
// 区间dp，dp[i][j]代表把i+1到j-1都打完的最大值；集合划分方式是最后一个打的气球k
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for(int i = 1; i <= n; i++) a[i] = nums[i - 1];
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for(int len = 3; len <= n + 2; len++){
            for(int i = 0; i + len - 1 < n + 2; i++){
                int j = i + len - 1;
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};