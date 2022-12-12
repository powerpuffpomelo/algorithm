// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> tmp = nums;
        for(int i = 0; i < n; i++){
            nums[i] = tmp[(i + n - k) % n];
        }
    }
};