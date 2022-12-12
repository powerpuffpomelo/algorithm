// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int ans = 0;
    void dfs(vector<int>& nums, int target, int u, int s){
        if(u == nums.size()){
            if(s == target) ans++;
            return;
        }
        dfs(nums, target, u + 1, s + nums[u]);
        dfs(nums, target, u + 1, s - nums[u]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target, 0, 0);
        return ans;
    }
};