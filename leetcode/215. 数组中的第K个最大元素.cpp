// ###################################################### 版本4 ###################################################### //
// 部分快排
class Solution {
public:
    int quick_sort(vector<int> &nums, int l, int r, int k){
        if(l >= r) return nums[k];
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while(i < j){
            do i++; while(nums[i] > x);
            do j--; while(nums[j] < x);
            if(i < j) swap(nums[i], nums[j]);
        }
        if(j >= k) return quick_sort(nums, l, j, k);
        else return quick_sort(nums, j + 1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        k--;
        return quick_sort(nums, 0, nums.size() - 1, k);
    }
};

// ###################################################### 版本3 ###################################################### //
// 部分快排
class Solution {
public:
    int quick_sort(vector<int> &nums, int l, int r, int k){
        if(l >= r) return nums[l];
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while(i < j){
            do i++; while(nums[i] > x);
            do j--; while(nums[j] < x);
            if(i < j) swap(nums[i], nums[j]);
        }
        if(j - l + 1 >= k) return quick_sort(nums, l, j, k);
        else return quick_sort(nums, j + 1, r, k - j + l - 1);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k);
    }
};

// ###################################################### 版本2 ###################################################### //
// 快排
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

// ###################################################### 版本1 ###################################################### //
// 快排
class Solution {
public:
    int n;
    void quick_sort(vector<int> &nums, int l, int r){
        if(l >= r) return;
        int i = l, j = r;
        int x = nums[i];
        while(i < j){
            while(i < j && nums[j] < x) j--;
            nums[i] = nums[j];
            while(i < j && nums[i] >= x) i++;
            nums[j] = nums[i];
        }
        nums[i] = x;
        quick_sort(nums, l, i - 1);
        quick_sort(nums, i + 1, r);
    }
    int findKthLargest(vector<int>& nums, int k) {
        n = nums.size();
        quick_sort(nums, 0, n - 1);
        return nums[k - 1];
    }
};