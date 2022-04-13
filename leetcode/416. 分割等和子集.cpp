class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(auto x : nums) s += x;
        if(s % 2) return false;
        int target = s / 2;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = target; j >= nums[i - 1]; j--){
                if(dp[j - nums[i - 1]]){
                    dp[j] = 1;
                }
            }
        }
        return dp[target] == 1;
    }
};