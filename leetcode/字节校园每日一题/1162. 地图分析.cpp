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