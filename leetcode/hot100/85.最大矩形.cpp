// ###################################################### 版本3 ###################################################### //
// 单调栈
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> left_num(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    left_num[i][j] = (j == 0 ? 0 : left_num[i][j - 1]) + 1;
                }
            }
        }
        for(int j = 0; j < col; j++){   // 对于每一列，使用基于柱状图的方法
            vector<int> up(row, 0), down(row, 0);   // ij这个点两侧的柱状图，第一个高度比ij小的位置
            stack<int> stk;
            for(int i = 0; i < row; i++){
                while(stk.size() && left_num[stk.top()][j] >= left_num[i][j]) stk.pop();
                up[i] = stk.size() ? stk.top() : -1;
                stk.push(i);
            }
            stk = stack<int>();
            for(int i = row - 1; i >= 0; i--){
                while(stk.size() && left_num[stk.top()][j] >= left_num[i][j]) stk.pop();
                down[i] = stk.size() ? stk.top() : row;
                stk.push(i);
            }
            for(int i = 0; i < row; i++){
                int height = down[i] - up[i] - 1;
                int area = left_num[i][j] * height;
                ans = max(ans, area);
            }
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 柱状图最大矩形
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size(), col = matrix[0].size();
        int left_num[row + 1][col + 1];   // 记录该点左侧最多连续1数量
        for(int i = 1; i <= row; i++){
            left_num[i][0] = 0;
            for(int j = 1; j <= col; j++){
                left_num[i][j] = (matrix[i - 1][j - 1] == '1' ? left_num[i][j - 1] + 1 : 0);
            }
        }
        for(int i =  1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                int w = j;
                for(int k = i; k >= 1; k--){
                    int h = i - k + 1;
                    w = min(w, left_num[k][j]);
                    ans = max(ans, h * w);
                }
            }
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 同1
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> left_num(row, vector<int>(col, 0));  // vector作为二维数组初始化
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    left_num[i][j] = (j == 0 ? 0 : left_num[i][j - 1]) + 1;
                }
            }
        }
        for(int i =  0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '0') continue;
                int width = left_num[i][j];
                int area = width;
                for(int k = i; k >= 0; k--){
                    if(matrix[k][j] == '0') break;
                    width = min(width, left_num[k][j]);
                    area = max(area, width * (i - k + 1));
                }
                ans = max(ans, area);
            }
        }
        return ans;
    }
};

