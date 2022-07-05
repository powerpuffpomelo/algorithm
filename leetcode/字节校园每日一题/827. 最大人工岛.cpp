// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    unordered_map<int, int> color2cnt;
    vector<vector<int>> color;
    int n, ans = 1;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int get_color(int i, int j, int c, vector<vector<int>>& grid){
        color[i][j] = c;
        int ret = 1;
        for(int d = 0; d < 4; d++){
            int a = i + dx[d], b = j + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= n || !grid[a][b] || color[a][b]) continue;
            ret += get_color(a, b, c, grid);
        }
        return ret;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        color = vector<vector<int>>(n, vector<int>(n));
        int c = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !color[i][j]){
                    color2cnt[c] = get_color(i, j, c, grid);
                    ans = max(ans, color2cnt[c]);
                    c++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    set<int> se;
                    for(int d = 0; d < 4; d++){
                        int a = i + dx[d], b = j + dy[d];
                        if(a < 0 || a >= n || b < 0 || b >= n) continue;
                        se.insert(color[a][b]);
                    }
                    int sum = 1;
                    for(int c : se){
                        sum += color2cnt[c];
                    }
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};