// ###################################################### 版本2 ###################################################### //
// 45°翻转+水平翻转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i + 1; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size() / 2; j++){
                swap(matrix[i][j], matrix[i][matrix.size() - j - 1]);
            }
        }
    }
};

// ###################################################### 版本1 ###################################################### //
// 水平翻转+45°翻转
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