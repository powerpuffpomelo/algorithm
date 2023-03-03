/*
最简单的构造：
如果排序后的数组中存在k对标记，那么最小的k个元素和最大的k个元素一定满足条件。
所以第一个元素从前一半找，第二个元素从后一半找，是一定能找到最多的标记的。
*/
// ###################################################### 版本2 ###################################################### //
// 双指针
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0, j = n / 2; i < n / 2; i++){
            while(j < n && nums[j] < 2 * nums[i]) j++;
            if(j < n){
                ans += 2;
                j++;
            }
        }
        return ans;
    }
};

// ###################################################### 版本3 ###################################################### //
// 二分，如果不知道怎么构造，就二分试答案！
class Solution {
public:
    bool check(int x, vector<int>& nums){
        int n = nums.size();
        for(int i = 0, j = n - x; j < n; i++, j++){
            if(nums[i] * 2 > nums[j]) return false;
        }
        return true;
    }
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n / 2;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(mid, nums)) l = mid;
            else r = mid - 1;
        }
        return l * 2;
    }
};
