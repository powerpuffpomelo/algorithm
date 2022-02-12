// todo 其它方法
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n / 2; j++){
                int k = n - 1 - j;
                swap(matrix[i][j], matrix[i][k]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; i + j < n - 1; j++){
                int x = n - j - 1, y = n - i - 1;
                swap(matrix[i][j], matrix[x][y]);
            }
        }
    }
};