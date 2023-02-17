// ###################################################### 版本4 ###################################################### //
// 更简洁的做法，无需求最大/最小值
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r>> 1;
            if(nums[mid] <= nums[r]){
                if(target > nums[mid] && target <= nums[r]) l = mid + 1;
                else r = mid;
            }else{
                if(target <= nums[mid] && target >= nums[l]) r = mid;
                else l = mid + 1;
            }
        }
        if(nums[l] == target) return l;
        else return -1;
    }
};

// ###################################################### 版本2 ###################################################### //
// 简洁一点的写法，先找到最大值位置，然后正常二分
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] > nums[0]) l = mid;
            else r = mid - 1;
        }
        if(nums[0] <= target) l = 0;
        else l += 1, r = nums.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if(nums[r] == target) return r;  // 此处如果写l会报错，因为如果nums.size() == 1的话，不会进入while循环，l > r, l会越界
        else return -1;
    }
};

// ###################################################### 版本3 ###################################################### //
// 
class Solution {
public:
    int find_max(vector<int>& nums, int l, int r){
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] > nums[l]) l = mid;
            else r = mid - 1;
        }
        return l;
    }
    int find(vector<int>& nums, int l, int r, int target){
        if(l > r) return -1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if(nums[l] == target) return l;
        else return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mmax = find_max(nums, 0, n - 1);
        if(target >= nums[0]) return find(nums, 0, mmax, target);
        else return find(nums, mmax + 1, n - 1, target);
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，先找到最大值位置，然后再二分
class Solution {
public:
    int n;
    int search_max(vector<int>& nums, int l, int r){
        int ret = r;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1]) && mid != ret) return mid;
            else if(nums[mid] <= nums[ret]) r = mid - 1;
            else l = mid;
        }
        return l;
    }
    int binary_search(vector<int>& nums, int l, int r, int target){
        if(l > r) return -1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        if(nums[l] != target) return -1;
        else return l;
    }
    int search(vector<int>& nums, int target) {
        n = nums.size();
        int p_max = search_max(nums, 0, n - 1);
        if(nums[0] <= target && nums[p_max] >= target) return binary_search(nums, 0, p_max, target);
        else return binary_search(nums, p_max + 1, n - 1, target);
    }
};