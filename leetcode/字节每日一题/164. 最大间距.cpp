// ###################################################### 版本1 ###################################################### //
// 基于桶的算法，最大间距一定>=平均间距，只要维护一堆平均间距长度的桶，就可以保证最大间距在桶之间而非桶内部产生
class Solution {
public:
    struct range{
        int l, r;
        range(): l(INT_MAX), r(INT_MIN) {}
    };
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int Min = *min_element(nums.begin(), nums.end());
        int Max = *max_element(nums.begin(), nums.end());
        int len = max(1, (Max - Min) / (n - 1));  // 每个桶的长度
        vector<range> ranges((Max - Min) / len + 1);
        
        for(int x : nums){
            int i = (x - Min) / len;
            ranges[i].l = min(ranges[i].l, x);
            ranges[i].r = max(ranges[i].r, x);
        }
        int ans = 0;
        
        for(int i = 0, last = Min; i < ranges.size(); i++){
            if(ranges[i].l == INT_MAX) continue;
            ans = max(ans, ranges[i].l - last);
            last = ranges[i].r;
        }
        return ans;
    }
};