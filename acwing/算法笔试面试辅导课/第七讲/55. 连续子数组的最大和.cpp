// ###################################################### 版本2 ###################################################### //
// 优雅
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1, s = nums[0]; i < nums.size(); i++){
            s = nums[i] + max(0, s);
            ans = max(ans, s);
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 我的初版
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9;
        vector<int> dp(nums.size());
        fill(dp.begin(), dp.end(), -1e9);
        for(int i = 0; i < nums.size(); i++){
            dp[i] = nums[i];
            if(i) dp[i] = max(dp[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
