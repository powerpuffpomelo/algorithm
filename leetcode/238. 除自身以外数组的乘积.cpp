// ###################################################### 版本2 ###################################################### //
// 额外空间复杂度O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n, 1);
        for(int i = 1; i < n; i++) p[i] = p[i - 1] * nums[i - 1];
        for(int i = n - 1, s = 1; i >= 0; i--){
            p[i] *= s;
            s *= nums[i];
        }
        return p;
    }
};

// ###################################################### 版本1 ###################################################### //
// 额外空间复杂度O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n), ans(n);
        left[0] = right[n - 1] = 1;
        for(int i = 1; i < n; i++) left[i] = left[i - 1] * nums[i - 1];
        for(int i = n - 2; i >= 0; i--) right[i] = right[i + 1] * nums[i + 1];
        for(int i = 0; i < n; i++) ans[i] = left[i] * right[i];
        return ans;
    }
};