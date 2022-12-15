// ###################################################### 版本1 ###################################################### //
// dp, f[i]表示偷第i家的最大金额，g[i]表示不偷第i家的最大金额
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> f(nums.size() + 1), g(nums.size() + 1);
        for(int i = 1; i <= nums.size(); i++){
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[nums.size()], g[nums.size()]);
    }
};

// ###################################################### 版本1 ###################################################### //
// dp, dp[i]表示偷第i家的最大金额
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            dp[i] = nums[i];
            if(i - 2 >= 0) dp[i] = max(dp[i], dp[i - 2] + nums[i]);
            if(i - 3 >= 0) dp[i] = max(dp[i], dp[i - 3] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};