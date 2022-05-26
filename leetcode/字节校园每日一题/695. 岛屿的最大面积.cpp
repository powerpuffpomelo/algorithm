// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int ans = 0;
    int n, m;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    void dfs(int i, int j, int& s, vector<vector<int>>& grid, vector<vector<int>>& vis){
        s++;
        vis[i][j] = 1;
        for(int d = 0; d < 4; d++){
            int a = i + dx[d], b = j + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || !grid[a][b] || vis[a][b]) continue;
            dfs(a, b, s, grid, vis);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !vis[i][j]){
                    int s = 0;
                    dfs(i, j, s, grid, vis);
                    ans = max(ans, s);
                } 
            }
        }
        return ans;
    }
};