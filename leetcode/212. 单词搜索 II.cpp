// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    unordered_set<string> se, ret;
    vector<vector<int>> vis;
    int n, m, maxlen = 0;
    vector<string> ans;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<char>>& board, int i, int j, string& temp){
        if(se.count(temp)) ret.insert(temp);
        if(temp.size() == maxlen) return;  // maxlen剪枝，已经超出最长单词长度，就无需继续搜索
        for(int d = 0; d < 4; d++){
            int a = i + dx[d], b = j + dy[d];
            if(a >= 0 && a < n && b >= 0 && b < m && !vis[a][b]){
                temp += board[a][b];
                vis[a][b] = 1;
                dfs(board, a, b, temp);
                temp.pop_back();
                vis[a][b] = 0;
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto w : words){
            se.insert(w);
            maxlen = max(maxlen, (int)w.size());
        }
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vis[i][j] = 1;
                string temp;
                temp += board[i][j];
                dfs(board, i, j, temp);
                temp.pop_back();
                vis[i][j] = 0;
            }
        }
        for(auto s : ret) ans.push_back(s);
        return ans;
    }
};