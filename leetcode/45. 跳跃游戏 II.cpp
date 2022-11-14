// ###################################################### 版本2 ###################################################### //
// 绝绝子的dp，时间复杂度O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        for(int i = 1, j = 0; i < nums.size(); i++){
            while(j + nums[j] < i) j++;    // j是能一步走到i的最小位置j
            dp[i] = dp[j] + 1;
        }
        return dp[nums.size() - 1];
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版 dp，时间复杂度O(n^2)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 1e4 + 10);
        dp[0] = 0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] >= i - j) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[nums.size() - 1];
    }
};