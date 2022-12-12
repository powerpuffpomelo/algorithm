// ###################################################### 版本1 ###################################################### //
// 我的初版，记忆化搜索
class Solution {
public:
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;
    int cal(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[i][j]) return dp[i][j];
        dp[i][j] = 1;
        for(int d = 0; d < 4; d++){
            int a = i + dx[d], b = j + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || matrix[a][b] >= matrix[i][j]) continue;
            dp[i][j] = max(dp[i][j], cal(a, b, matrix, dp) + 1);
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, cal(i, j, matrix, dp));
            }
        }
        return ans;
    }
};