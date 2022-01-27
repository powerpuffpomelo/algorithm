// ###################################################### 版本2 ###################################################### //
// 单指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) swap(nums[i], nums[ptr++]);
        }
        for(int i = ptr; i < n; i++){
            if(nums[i] == 1) swap(nums[i], nums[ptr++]);
        }
    }
};

// ###################################################### 版本3 ###################################################### //
// 双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) swap(nums[i], nums[p1++]);
            else if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                if(p0 < p1) swap(nums[i], nums[p1]);
                p0++, p1++;
            }
        }
    }
};

// ###################################################### 版本4 ###################################################### //
// 双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for(int i = 0; i <= p2; i++){
            if(nums[i] == 0) swap(nums[i], nums[p0++]);
            else if(nums[i] == 2) swap(nums[i--], nums[p2--]);
        }
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，快排
class Solution {
    void quick_sort(vector<int>& nums, int l, int r, int limit){
        if(l >= r) return;
        int x = nums[l], i = l, j = r;
        while(i < j){
            while(i < j && nums[j] > limit) j--;
            nums[i] = nums[j];
            while(i < j && nums[i] == limit) i++;
            nums[j] = nums[i];
        }
        nums[i] = x;
        if(limit == 0){
            if(x) quick_sort(nums, i, r, 1);
            else quick_sort(nums, i + 1, r, 1);
        }
    }
public:
    void sortColors(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1, 0);

    }
};