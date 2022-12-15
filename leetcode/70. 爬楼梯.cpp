// ###################################################### 版本2 ###################################################### //
// 递推
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// ###################################################### 版本2 ###################################################### //
// 递归
class Solution {
public:
    vector<int> dp;
    int cal(int x){
        if(dp[x]) return dp[x];
        else return dp[x] = cal(x - 1) + cal(x - 2);
    }
    int climbStairs(int n) {
        dp = vector<int>(n + 1);
        dp[0] = dp[1] = 1;
        return cal(n);
    }
};