/*
本题是dp
dp[i]表示以第i个数为结尾的区间的最大值
dp[i] = max(dp[i], dp[i - 1] + nums[i]);
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i = 0, last = 0; i < nums.size(); i++){
            last = nums[i] + max(last, 0);   // dp[i]只需要利用dp[i - 1]，所以可以用last变量滚动记录
            ans = max(ans, last);
        }
        return ans;
    }
};