// ###################################################### 版本1 ###################################################### //
// dfs，要用邻接表才不会超时
class Solution {
public:
    int dfs(vector<vector<int>>& g, vector<bool>& hasApple, int u, int pre){
        int ret = 0;
        for(int v : g[u]){
            if(v != pre){
                int t = dfs(g, hasApple, v, u);
                if(t || hasApple[v]) ret += t + 1;
            }
        }
        return ret;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n);
        for(auto e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        return dfs(g, hasApple, 0, -1) * 2;
    }
};