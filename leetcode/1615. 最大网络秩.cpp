// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<set<int>> adj;
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        adj.resize(n + 1);
        for(auto e : roads){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int temp = adj[i].size() + adj[j].size() - (adj[i].count(j) ? 1 : 0);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};