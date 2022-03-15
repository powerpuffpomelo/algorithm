// ###################################################### 版本1 ###################################################### //
// dfs，新建vis
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
// dfs，复制一个相同的图，原地修改
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

// ###################################################### 版本3 ###################################################### //
// bfs
class Solution {
public:
    typedef pair<int, int> pii;
    int n, m;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    vector<vector<char>> g;
    void bfs(int i, int j){
        queue<pii> q;
        q.push({i, j});
        g[i][j] = '0';
        while(q.size()){
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for(int d = 0; d < 4; d++){
                int a = x + dx[d], b = y + dy[d];
                if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '0') continue;
                g[a][b] = '0';  // 使用bfs的话，这里要立刻修改然后入队，否则，如果只有取出队首才修改，会超时，因为一个元素可能多次入队
                q.push({a, b});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        g = grid;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == '1'){
                    bfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};