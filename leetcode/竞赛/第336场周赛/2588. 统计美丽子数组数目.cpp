// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;   // 注意数据范围
        unordered_map<int, int> cnt;
        int sum = 0;
        cnt[0]++;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            sum = sum ^ x;
            ans += cnt[sum];
            cnt[sum]++;
        }
        return ans;
    }
};