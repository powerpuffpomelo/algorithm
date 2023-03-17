// ###################################################### 版本1 ###################################################### //
// 我的初版
/*
哈希表，前缀异或 O(n)
 - 美丽的子数组相当于子数组内数字的异或值为0
 - 对于区间[l, r]的异或值，可以通过前缀r异或前缀l-1得到
 - 按顺序遍历数组，哈希表cnt记录当前所有前缀中某个异或值的个数，初始时cnt[0]=1
*/
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