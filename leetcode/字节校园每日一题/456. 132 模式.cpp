// ###################################################### 版本1 ###################################################### //
// 单调栈，时间复杂度O(n)
// 满足要求的元素ai, aj, ak; right维护最大的ak
class Solution {
public:
    stack<int> stk;
    bool find132pattern(vector<int>& nums) {
        int right = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < right) return true;
            while(stk.size() && nums[i] > stk.top()){
                right = max(right, stk.top());
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};