// ###################################################### 版本2 ###################################################### //
// 原地哈希
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 || nums[i] >= nums.size()) return -1;
        }
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != i && nums[i] != nums[nums[i]]) swap(nums[i], nums[nums[i]]);
            if(nums[i] != i) return nums[i];
        }
        return -1;
    }
};

// ###################################################### 版本1 ###################################################### //
// 哈希
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        unordered_set<int> se;
        for(int x : nums){
            if(x < 0 || x >= nums.size()) return -1;
        }
        for(int x : nums){
            if(!se.count(x)) se.insert(x);
            else return x;
        }
        return -1;
    }
};

