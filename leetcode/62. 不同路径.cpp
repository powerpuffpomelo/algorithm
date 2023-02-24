// ###################################################### 版本1 ###################################################### //
// dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i) dp[i][j] += dp[i - 1][j];
                if(j) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// ###################################################### 版本2 ###################################################### //
// 组合数学，从m+n-2次移动中选择m-1次
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for(int x = n, y = 1; y < m; x++, y++){
            ans = ans * x / y;
        }
        return ans;
    }
};