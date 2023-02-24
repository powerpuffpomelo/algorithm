// ###################################################### 版本3 ###################################################### //
// 用j存储能跳到的最远的位置
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0, j = 0; i < nums.size(); i++){
            if(j < i) return false;
            j = max(j, i + nums[i]);
        }
        return true;
    }
};

// ###################################################### 版本2 ###################################################### //
// dp dp[i]表示能否跳到
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size());
        for(int i = 1, j = 0; i < nums.size(); i++){
            while(j < i && j + nums[j] < i) j++;
            if(j == i) return false;
        }
        return true;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，bfs
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        queue<int> q;
        vector<bool> inq(nums.size(), false);
        q.push(0);
        inq[0] = true;
        while(q.size()){
            auto t = q.front();
            q.pop();
            for(int i = 1; i <= nums[t]; i++){
                if(t + i == nums.size() - 1) return true;
                if(t + i < nums.size() && !inq[t + i]){
                    q.push(t + i);
                    inq[t + i] = true;
                }
            }
        }
        return false;
    }
};