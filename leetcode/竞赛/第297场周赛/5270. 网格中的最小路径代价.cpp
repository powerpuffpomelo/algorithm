// ###################################################### 版本2 ###################################################### //
// 一个dp数组
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size(), INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(m, INF));
        for(int i = 0; i < m; i++) dp[0][i] = grid[0][i];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
            }
        }
        int ans = INF;
        for(int i = 0; i < m; i++) ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，滚动数组
class Solution {
public:
    static const int INF = 1e9;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0), g(n, 0);
        for(int i = 0; i < n; i++){
            dp[i] = grid[0][i];
        }
        int ans = INF;
        for(int i = 1; i < m; i++){
            g.assign(dp.begin(), dp.end());
            fill(dp.begin(), dp.end(), INF);
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    dp[j] = min(dp[j], g[k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
                if(i == m - 1) ans = min(ans, dp[j]);
            }
        }
        return ans;
    }
};