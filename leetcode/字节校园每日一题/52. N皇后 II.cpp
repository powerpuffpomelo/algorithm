class Solution {
public:
    int ans = 0;
    int num;
    int col[10], dg[20], udg[20];
    void dfs(int r){
        if(r == num){
            ans++;
            return;
        }
        for(int i = 0; i < num; i++){
            if(!col[i] && !dg[i + r] && !udg[num + i - r]){
                col[i] = dg[i + r] = udg[num + i - r] = 1;
                dfs(r + 1);
                col[i] = dg[i + r] = udg[num + i - r] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        num = n;
        memset(col, 0, sizeof col);
        memset(dg, 0, sizeof dg);
        memset(udg, 0, sizeof udg);
        dfs(0);
        return ans;
    }
};