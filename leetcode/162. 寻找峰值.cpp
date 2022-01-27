// ###################################################### 版本2 ###################################################### //
// 纯二分到底
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            nums[mid] < nums[mid + 1] ? l = mid + 1 : r = mid;
        }
        return l;
    }
};

// ###################################################### 版本1 ###################################################### //
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(mid > 0 && nums[mid - 1] > nums[mid]){
                r = mid - 1;
                continue;
            }
            if(mid < n - 1 && nums[mid + 1] > nums[mid]){
                l = mid + 1;
                continue;
            }
            ans = mid;
            break;
        }
        return ans;
    }
};