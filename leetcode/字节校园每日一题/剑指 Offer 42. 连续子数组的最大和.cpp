// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9;
        for(int i = 0, s = 0; i < nums.size(); i++){
            s = max(s, 0);
            s += nums[i];
            ans = max(ans, nums[i]);
            ans = max(ans, s);
        }
        return ans;
    }
};