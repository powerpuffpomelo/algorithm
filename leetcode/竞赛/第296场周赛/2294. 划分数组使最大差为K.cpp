// ###################################################### 版本2 ###################################################### //
// 排序，数据范围1e5，时间复杂度是可以O(nlogn)的！
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        for(int i = 1, j = 0; i < nums.size(); i++){
            if(nums[i] - nums[j] > k){
                j = i;
                ans++;
            }
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，哈希表
class Solution {
public:
    static const int N = 1e5 + 10;
    int have[N];
    int partitionArray(vector<int>& nums, int k) {
        memset(have, 0, sizeof have);
        for(auto x : nums){
            have[x] = 1;
        }
        int ans = 0, mmin = -1;
        for(int i = 0; i <= 1e5; i++){
            if(have[i]){
                if(mmin == -1 || i - mmin > k){
                    ans++;
                    mmin = i;
                }
            }
        }
        return ans;
    }
};