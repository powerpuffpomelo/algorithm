// ###################################################### 版本1 ###################################################### //
// 枚举
// 矩形四个点都不固定，所以通过打表存下来一个维度，可以变成O(n^3)复杂度
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        vector<vector<int>> row(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // 枚举以ij为右下角的矩形数量
                if(mat[i][j] == 0) continue;
                if(!j) row[i][j] = 1;
                else row[i][j] = row[i][j - 1] + 1;
                int col = row[i][j];
                for(int k = i; k >= 0 && col; k--){
                    col = min(col, row[k][j]);
                    ans += col;
                }
            }
        }
        return ans;
    }
};