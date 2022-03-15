// ###################################################### 版本1 ###################################################### //
// 新建vis
class Solution {
public:
    int n, m;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};  // 定义在class里的数组，必须标注大小
    vector<vector<int>> vis;
    void dfs(vector<vector<char>>& grid, int i, int j){
        vis[i][j] = 1;
        for(int d = 0; d < 4; d++){
            int a = i + dx[d], b = j + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || grid[a][b] == '0' || vis[a][b]) continue;
            dfs(grid, a, b);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 复制一个相同的图，原地修改
class Solution {
public:
    int n, m;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    vector<vector<char>> g;
    void dfs(vector<vector<char>>& g, int i, int j){
        g[i][j] = '0';
        for(int d = 0; d < 4; d++){
            int a = i + dx[d], b = j + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '0') continue;
            dfs(g, a, b);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        g = grid;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == '1'){
                    dfs(g, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};