class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] < nums[n - 1]) r = mid;   // 注意要和右端点比较，因为可能数组就是升序的
            else l = mid + 1;
        }
        return nums[l];
    }
};