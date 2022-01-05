// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
    int m, n;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    // 如果要用到外部变量，就当作参数一起传入
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string& word, vector<vector<int>>& visited){
        if(idx == word.size() - 1) return true;
        for(int k = 0; k < 4; k++){
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[idx + 1] && !visited[x][y]){
                visited[x][y] = 1;
                if(dfs(x, y, idx + 1, board, word, visited)) return true;
                visited[x][y] = 0;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));  // 防止回头
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = 1;
                    if(dfs(i, j, 0, board, word, visited)) return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }