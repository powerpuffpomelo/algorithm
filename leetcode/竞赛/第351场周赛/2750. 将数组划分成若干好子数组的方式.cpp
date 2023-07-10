// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;
        int pre = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                if(pre != -1){
                    ans = ans * (i - pre) % mod;
                }
                pre = i;
            }
        }
        if(pre == -1) ans = 0;
        return ans;
    }
};