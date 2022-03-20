// 找到第一个顺序对，在其右侧找到最小的那个（也就是最后一个）比它大的数字，交换；而后翻转后侧的逆序序列
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = n - 1;
        while(k > 0 && nums[k] <= nums[k - 1]) k--;   // 注意数字可能重复
        if(k == 0) reverse(nums.begin(), nums.end());
        else{
            int t = k;
            while(t < nums.size() && nums[t] > nums[k - 1]) t++;
            swap(nums[t - 1], nums[k - 1]);
            reverse(nums.begin() + k, nums.end());
        }
    }
};