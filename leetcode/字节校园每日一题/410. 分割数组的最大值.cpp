// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        vector<int> s(n + 1);
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int k = 1; k <= m; k++){
                for(int j = 0; j < i; j++){
                    dp[i][k] = min(dp[i][k], max(dp[j][k - 1], s[i] - s[j]));
                }
            }
        }
        return dp[n][m];
    }
};