// ###################################################### 版本2 ###################################################### //
// 多源bfs
#define x first
#define y second

typedef pair<int, int> PII;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(m, INF));
        queue<PII> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        while(q.size()){
            auto t = q.front();
            q.pop();
            for(int d = 0; d < 4; d++){
                int a = t.x + dx[d], b = t.y + dy[d];
                if(a < 0 || a >= n || b < 0 || b >= m) continue;
                if(dist[a][b] > dist[t.x][t.y] + 1){
                    dist[a][b] = dist[t.x][t.y] + 1;
                    q.push({a, b});
                }
            }
        }
        int ans = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j]) ans = max(ans, dist[i][j]);
            }
        }
        if(ans == INF) ans = -1;
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int n;
    int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, -1, 1};
    int cal_min_d(vector<vector<int>>& grid, int i, int j){
        int ret = 1;
        while(ret < n + n){
            int a = i - ret, b = j;
            for(int d = 0; d < 4; d++){
                for(int k = 0; k < ret; k++){
                    if(a >= 0 && a < n && b >= 0 && b < n && grid[a][b]) return ret;
                    a += dx[d], b += dy[d];
                }
            }
            ret++;
        }
        return -1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        this->n = grid.size();
        int c0 = 0, c1 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) c1++;
                else c0++;
            }
        }
        if(!c0 || !c1) return -1;
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]){
                    int min_d = cal_min_d(grid, i, j);
                    ans = max(ans, min_d);
                }
            }
        }
        return ans;
    }
};