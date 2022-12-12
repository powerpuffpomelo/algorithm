// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    bool row[9][9], col[9][9], cell[3][3][9];
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(cell, 0, sizeof cell);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int t = board[i][j] - '1';
                    row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
    bool dfs(vector<vector<char>>& board, int x, int y){
        if(y == 9) x++, y = 0;
        if(x == 9) return true;
        if(board[x][y] != '.') return dfs(board, x, y + 1);
        for(int i = 0; i < 9; i++){
            if(!row[x][i] && !col[y][i] && !cell[x / 3][y / 3][i]){
                board[x][y] = i + '1';
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = true;
                if(dfs(board, x, y + 1)) return true;      // 中途直接返回，保留ans，不还原现场
                board[x][y] = '.';
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = false;
            }
        }
        return false;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<unordered_set<char>> row, col, squ;
    bool flag = false;
    vector<vector<char>> ans;
    void dfs(int i, int j, vector<vector<char>>& board){
        if(j == 9) i++, j = 0;
        if(i == 9){
            flag = true;
            ans = board;
            return;
        }
        if(flag) return;
        if(board[i][j] != '.') dfs(i, j + 1, board);
        else{
            for(char c = '1'; c <= '9'; c++){
                if(row[i].count(c) || col[j].count(c) || squ[i / 3 * 3 + j / 3].count(c)) continue;
                board[i][j] = c;
                row[i].insert(c), col[j].insert(c), squ[i / 3 * 3 + j / 3].insert(c);
                dfs(i, j + 1, board);
                board[i][j] = '.';
                row[i].erase(c), col[j].erase(c), squ[i / 3 * 3 + j / 3].erase(c);
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9), col.resize(9), squ.resize(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    row[i].insert(c), col[j].insert(c);
                    squ[i / 3 * 3 + j / 3].insert(c);
                }
            }
        }
        dfs(0, 0, board);
        board = ans;
    }
};