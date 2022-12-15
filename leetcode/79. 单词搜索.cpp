// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    bool flag = false;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& board, string& word, int i, int j, int u){
        if(flag || u == word.size()){
            flag = true;
            return;
        }
        for(int d = 0; d < 4; d++){
            int a = i + dx[d], b = j + dy[d];
            if(a >= 0 && a < n && b >= 0 && b < m && !vis[a][b] && board[a][b] == word[u]){
                vis[a][b] = 1;
                dfs(board, word, a, b, u + 1);
                vis[a][b] = 0;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->n = board.size(), this->m = board[0].size();
        vis.resize(n, vector<int>(m));
        int u = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[u]){
                    vis[i][j] = 1;
                    dfs(board, word, i, j, u + 1);
                    if(flag) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};