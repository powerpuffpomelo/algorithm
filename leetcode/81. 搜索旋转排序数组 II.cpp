// ###################################################### 版本1 ###################################################### //
// 先找到最大值位置，然后正常二分
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(r && nums[r] == nums[l]) r--;   // 和31题区别
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[l]) l = mid;
            else r = mid - 1;
        }
        if(target >= nums[0]) l = 0;
        else l++, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return nums[r] == target;
    }
};