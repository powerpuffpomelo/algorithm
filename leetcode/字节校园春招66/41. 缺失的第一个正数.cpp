// ###################################################### 版本3 ###################################################### //
// 原地哈希2，每个数字到该到的地方去
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(nums[i] != i + 1){
                if(nums[i] < 1 || nums[i] > n || nums[i] == nums[nums[i] - 1]) break;
                swap(nums[i], nums[nums[i] - 1]);
            }

        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

// ###################################################### 版本2 ###################################################### //
// 原地哈希1：负数标记
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(auto &x : nums){   // 注意要引用&，不然不能改变
            if(x < 1 || x > n) x = n + 1;
        }
        for(auto x : nums){
            x = abs(x);
            if(x >= 1 && x <= n && nums[x - 1] > 0) nums[x - 1] = -nums[x - 1];
            //cout << x << ' ';
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};

// ###################################################### 版本1 ###################################################### //
// 哈希
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;  // 开set也行
        for(int x : nums) mp[x] = 1;
        int ans = 1;
        while(mp[ans]) ans++;
        return ans;
    }
};
