// ###################################################### 版本2 ###################################################### //
// 时间复杂度O(nlogn)
class Solution {
public:
    static const int N = 2510;
    int len2num[N], maxlen = 0;
    int lengthOfLIS(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int len = maxlen;
            while(len > 0 && nums[i] <= len2num[len]) len--;
            len2num[len + 1] = nums[i];
            maxlen = max(maxlen, len + 1);
        }
        return maxlen;
    }
};

// ###################################################### 版本1 ###################################################### //
// 时间复杂度O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};