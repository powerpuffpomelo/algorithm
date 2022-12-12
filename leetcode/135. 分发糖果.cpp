// ###################################################### 版本2 ###################################################### //
// 记忆化搜索
class Solution {
public:
    vector<int> dp;
    vector<int> w;
    int n;

    int candy(vector<int>& ratings) {
        n = ratings.size();
        w = ratings;
        dp.resize(n, -1);  // 初始化vector
        int ans = 0;
        for(int i = 0; i < n; i++) ans += cal(i);
        return ans;
    }

    int cal(int u){
        if(dp[u] != -1) return dp[u];
        dp[u] = 1;
        if(u && w[u] > w[u - 1]) dp[u] = max(dp[u], cal(u - 1) + 1);
        if(u + 1 < n && w[u] > w[u + 1]) dp[u] = max(dp[u], cal(u + 1) + 1);
        return dp[u];
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，贪心，正着修改一遍倒着修改一遍
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]) nums[i] = nums[i - 1] + 1;
        }
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]) nums[i] = max(nums[i], nums[i + 1] + 1);
        }
        int ans = 0;
        for(auto x : nums) ans += x;
        return ans;
    }
};