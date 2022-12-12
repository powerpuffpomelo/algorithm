// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int n, ans = 0;
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[i] = 1;
        for(int j = 0; j < n; j++){
            if(isConnected[i][j] && !vis[j]) dfs(j, isConnected, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<int> vis(n);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                ans++;
            }
        }
        return ans;
    }
};