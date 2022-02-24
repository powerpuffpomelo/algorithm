class Solution {
public:
    int getMaxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = dp[j];
                int left = j ? dp[j - 1] : 0;
                dp[j] = max(up, left) + grid[i][j];
            }
        }
        return dp[m - 1];
    }
};