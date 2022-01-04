// ###################################################### 版本1 ###################################################### //
// 哈希表
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority, cnt = 0;
        unordered_map<int, int> hash;
        for(int num : nums){
            hash[num]++;
            if(hash[num] > cnt){
                cnt = hash[num];
                majority = num;
            }
        }
        return majority;
    }
};

// ###################################################### 版本1 ###################################################### //
// 排序
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};