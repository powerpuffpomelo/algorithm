// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m));
        for(int j = 1; j < m; j++){
            int temp = 0;
            for(int i = 0; i < n; i++){
                if(i && grid[i - 1][j - 1] < grid[i][j] && (j == 1 || dp[i - 1][j - 1])) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                if(grid[i][j - 1] < grid[i][j] && (j == 1 || dp[i][j - 1])) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                if(i < n - 1 && grid[i + 1][j - 1] < grid[i][j] && (j == 1 || dp[i + 1][j - 1])) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                if(dp[i][j]) temp++;
                ans = max(ans, dp[i][j]);
            }
            if(!temp) break;
        }
        return ans;
    }
};