class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while(i < j){
            do i++; while(nums[i] > x);
            do j--; while(nums[j] < x);
            if(i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
    int findKthLargest(vector<int>& nums, int k) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums[k - 1];
    }
};