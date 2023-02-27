// ###################################################### 版本1 ###################################################### //
// 我的初版
typedef pair<int, int> pii;
class Solution {
public:
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    struct node{
        int x, y, d;
        bool operator<(const node &w)const{
            return d > w.d;
        }
    }nodes[100010];
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> inq(n, vector<int>(m, 0));
        priority_queue<node> q;
        q.push({0, 0, 0});
        while(q.size()){
            auto t = q.top();
            q.pop();
            if(vis[t.x][t.y]) continue;
            vis[t.x][t.y] = 1;
            if(t.x == n - 1 && t.y == m - 1) return t.d;
            for(int d = 0; d < 4; d++){
                int a = t.x + dx[d], b = t.y + dy[d];
                if(a >= 0 && a < n && b >= 0 && b < m && !vis[a][b]){
                    if(t.x == 0 && t.y == 0 && t.d + 1 < grid[a][b]) continue;
                    int dist;
                    if(t.d + 1 >= grid[a][b]) dist = t.d + 1;
                    else dist = grid[a][b] + ((grid[a][b] - t.d) % 2 == 0 ? 1 : 0);
                    q.push({a, b, dist});
                }
            }
        }
        return -1;
    }
};