// ###################################################### 版本2 ###################################################### //
// 有限状态自动机+位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for(int x : nums){
            one = (one ^ x) & ~two;
            two = (two ^ x) & ~one;
        }
        return one;
    }
};

// ###################################################### 版本1 ###################################################### //
// 排序
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 0; i < nums.size();){
            while(j < nums.size() && nums[j] == nums[i]) j++;
            if(j - i == 1) return nums[i];
            i = j;
        }
        return nums[nums.size() - 1];
    }
};