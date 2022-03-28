// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int i = l - 1, j = r + 1;
        int x = nums[l + r >> 1];
        while(i < j){
            do i++; while(nums[i] < x);
            do j--; while(nums[j] >  x);
            if(i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j), quick_sort(nums, j + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// ###################################################### 版本3 ###################################################### //
// 
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int i = l - 1, j = r + 1;
        int x = nums[l + r + 1 >> 1];
        while(i < j){
            do i++; while(nums[i] < x);
            do j--; while(nums[j] >  x);
            if(i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, i - 1), quick_sort(nums, i, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int x = nums[l + r >> 1];
        swap(nums[l], nums[l + r >> 1]);
        int i = l, j = r;
        while(i < j){
            while(i < j && nums[j] > x) j--;
            nums[i] = nums[j];
            while(i < j && nums[i] <= x) i++;
            nums[j] = nums[i];
        }
        nums[i] = x;
        quick_sort(nums, l, i - 1);
        quick_sort(nums, i + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};