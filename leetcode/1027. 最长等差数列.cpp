// ###################################################### 版本1 ###################################################### //
// dp[i][j] 代表以i结尾，且公差为j的子序列的最大长度
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 2;
        vector<vector<int>> dp(n, vector<int>(1010, 0));
        for(int i = 0; i < n; i++){
            for(int k = 0; k < i; k++){
                int j = nums[k] - nums[i] + 500;
                dp[i][j] = max(dp[i][j], 2);
                dp[i][j] = max(dp[i][j], dp[k][j] + 1);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};