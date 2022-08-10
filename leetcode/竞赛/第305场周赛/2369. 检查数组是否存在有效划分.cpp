// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            if((i - 1 >= 0 && nums[i] == nums[i - 1] && dp[i - 1]) || (i - 2 >= 0 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2] && dp[i - 2]) || (i - 2 >= 0 && nums[i - 1] + 1 == nums[i] && nums[i - 2] + 1 == nums[i - 1] && dp[i - 2])) dp[i + 1] = 1;
        }
        return dp[n];
    }
};