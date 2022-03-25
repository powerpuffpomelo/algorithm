class Solution {
public:
    int find_begin(vector<int>& nums, int target){
        if(!nums.size()) return -1;
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if(nums[l] != target) return -1;
        return l;
    }
    int find_end(vector<int>& nums, int target){
        if(!nums.size()) return -1;
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        if(nums[l] != target) return -1;
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {find_begin(nums, target), find_end(nums, target)};
    }
};