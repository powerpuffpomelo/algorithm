// ###################################################### 版本2 ###################################################### //
// 根据vis的数量判断退出
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        for(int cnt = 0, i = 0, j = 0, d = 0; cnt < n * m; cnt++){
            ans.push_back(matrix[i][j]);
            vis[i][j] = 1;
            int a = i + dx[d], b = j + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || vis[a][b]){
                d = (d + 1) % 4;
                a = i + dx[d], b = j + dy[d];
            }
            i = a, j = b;
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，根据还能不能继续走 来判断退出
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int d = 0;
        int i = 0, j = 0;
        while(true){
            ans.push_back(matrix[i][j]);
            vis[i][j] = 1;
            int a = i + dx[d], b = j + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || vis[a][b]) d = (d + 1) % 4;
            a = i + dx[d], b = j + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || vis[a][b]) break;
            i = a, j = b;
        }
        return ans;
    }
};

