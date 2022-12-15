// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = 1, ans = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]) len++;
            else len = 1;
            ans = max(ans, len);
        }
        return ans;
    }
};