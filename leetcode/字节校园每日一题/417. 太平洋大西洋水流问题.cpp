// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    typedef pair<int, int> pii;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pac(n, vector<int>(m)), atl(n, vector<int>(m));
        queue<pii> pacq, atlq;
        for(int i = 0; i < n; i++){
            pac[i][0] = 1;
            atl[i][m - 1] = 1;
            pacq.push({i, 0});
            atlq.push({i, m - 1});
        }
        for(int j = 0; j < m; j++){
            pac[0][j] = 1;
            atl[n - 1][j] = 1;
            pacq.push({0, j});
            atlq.push({n - 1, j});
        }
        while(pacq.size()){
            auto t = pacq.front();
            pacq.pop();
            int x = t.first, y = t.second;
            for(int d = 0; d < 4; d++){
                int a = x + dx[d], b = y + dy[d];
                if(a >= 0 && a < n && b >= 0 && b < m && !pac[a][b] && heights[a][b] >= heights[x][y]){
                    pac[a][b] = 1;
                    pacq.push({a, b});
                }
            }
        }
        while(atlq.size()){
            auto t = atlq.front();
            atlq.pop();
            int x = t.first, y = t.second;
            for(int d = 0; d < 4; d++){
                int a = x + dx[d], b = y + dy[d];
                if(a >= 0 && a < n && b >= 0 && b < m && !atl[a][b] && heights[a][b] >= heights[x][y]){
                    atl[a][b] = 1;
                    atlq.push({a, b});
                }
            }
        }
        vector<vector<int>> ret;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pac[i][j] && atl[i][j]){
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }
};