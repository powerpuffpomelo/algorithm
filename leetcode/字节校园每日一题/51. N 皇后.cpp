// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int n;
    vector<vector<string>> ans;
    vector<int> col, dg, udg;
    vector<string> temp;
    void dfs(int r, int c){
        if(r == n - 1){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!col[i] && !dg[r + 1 + i] && !udg[n + r + 1 - i]){
                temp[r + 1][i] = 'Q';
                col[i] = dg[r + 1 + i] = udg[n + r + 1 - i] = 1;
                dfs(r + 1, i);
                temp[r + 1][i] = '.';
                col[i] = dg[r + 1 + i] = udg[n + r + 1 - i] = 0;
            } 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        col.resize(n), dg.resize(2 * n), udg.resize(2 * n);
        string str;
        for(int j = 0; j < n; j++) str += '.';
        temp = vector<string>(n, str);
        for(int i = 0; i < n; i++){
            temp[0][i] = 'Q';
            col[i] = dg[i] = udg[n - i] = 1;
            dfs(0, i);
            temp[0][i] = '.';
            col[i] = dg[i] = udg[n - i] = 0;
        }
        return ans;
    }
};