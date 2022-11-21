class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r && nums[r] == nums[l]) r--;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] <= nums[r]) r = mid;  // 注意这里nums[r]不能改成nums[l]，因为nums[l]本身可能是最小值
            else l = mid + 1;
        }
        return nums[l];
    }
};