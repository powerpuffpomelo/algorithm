// ###################################################### 版本1 ###################################################### //
// 从低位到高位贪心
// 数学归纳：如果数组中 <= 2^i 的数之和 >= 2^i，则必然能凑出 2^i
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        if(accumulate(nums.begin(), nums.end(), 0LL) < target) return -1;
        long long cnt[31]{};  // map
        for(int x : nums) cnt[__builtin_ctz(x)]++; // 二进制1在第几位
        int ans = 0, i = 0;
        long long s = 0;  // 目前累积和
        while((1LL << i) <= target){   // >target无需考虑
            s += cnt[i] << i;
            int mask = (1LL << ++i) - 1;
            if(s >= (target & mask)) continue;   // &mask是为了取target的i位后面的部分
            ans++;  // 因为刚才++i了，需要补一个
            for(; cnt[i] == 0; i++) ans++;  // 寻找更大的数中  // 这期间所有i跳过即可，因为分解的时候都能出现
        }
        return ans;
    }
};