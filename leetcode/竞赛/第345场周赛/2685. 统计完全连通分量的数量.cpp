// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    void dfs(int i, int n, vector<int> &vis, vector<vector<int>> &g, unordered_set<int> &se){
        vis[i] = 1;
        se.insert(i);
        for(int j = 0; j < n; j++){
            if(!vis[j] && g[i][j]) dfs(j, n, vis, g, se);
        }
    }
    bool check(unordered_set<int> &se, int n, vector<vector<int>> &g){
        for(auto u : se){
            for(int v = 0; v < n; v++){
                if(v == u) continue;
                if(g[u][v] && !se.count(v)) return false;
                if(!g[u][v] && se.count(v)) return false;
            }
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> g(n, vector<int>(n));
        for(auto e : edges){
            g[e[0]][e[1]] = g[e[1]][e[0]] = 1;
        }
        vector<int> vis(n);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                unordered_set<int> se;
                dfs(i, n, vis, g, se);
                if(check(se, n, g)) ans++;
            }
        }
        return ans;
    }
};