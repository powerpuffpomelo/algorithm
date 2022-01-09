// ###################################################### 版本1 ###################################################### //
// 我的初版，哈希表
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto x : nums){
            cnt[x]++;
            if(cnt[x] > 1) return true;
        }
        return false;
    }
};

// ###################################################### 版本2 ###################################################### //
// 排序
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};

// ###################################################### 版本3 ###################################################### //
// 集合
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums){
            if(s.find(x) != s.end()) return true;
            s.insert(x);
        }
        return false;
    }
};