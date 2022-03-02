// ###################################################### 版本2 ###################################################### //
// 简洁方法
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        unordered_set<int> se;
        for(int x : nums){
            if(se.count(target - x)) return {x, target - x};
            se.insert(x);
        }
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        vector<int> ret;
        while(i < j){
            if(nums[i] + nums[j] == target){
                ret.push_back(nums[i]), ret.push_back(nums[j]);
                return ret;
            }else if(nums[i] + nums[j] < target) i++;
            else j--;
        }
    }
};

