// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size(), 0);
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
                dp[i] = dp[i - 1] + 1;
                ans += dp[i];
            }
        }
        return ans;
    }
};