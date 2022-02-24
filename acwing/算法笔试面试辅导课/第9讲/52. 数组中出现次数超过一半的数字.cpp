// ###################################################### 版本3 ###################################################### //
// 时间O(n) 空间O(1)
class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int val, cnt = 0;
        for(auto x : nums){
            if(!cnt){
                val = x;
                cnt++;
            }else{
                if(x == val) cnt++;
                else cnt--;
            }
        }
        return val;
    }
};

// ###################################################### 版本1 ###################################################### //
// 排序
class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }
};

// ###################################################### 版本2 ###################################################### //
// 哈希
class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        unordered_map<int, int> hashh;
        int n = nums.size();
        for(auto x : nums){
            hashh[x]++;
            if(hashh[x] > n / 2) return x;
        }
    }
};
