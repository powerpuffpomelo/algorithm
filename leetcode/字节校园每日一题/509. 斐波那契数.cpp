class Solution {
public:
    int dp[35];
    int dfs(int n){
        if(dp[n] != -1) return dp[n];
        return dp[n] = dfs(n - 1) + dfs(n - 2);
    }
    int fib(int n) {
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        dp[1] = 1;
        return dfs(n);
    }
};