// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> ind(n);
        for(auto p : pre){
            adj[p[1]].push_back(p[0]);
            ind[p[0]]++;
        }
        queue<int> q;
        vector<int> inq(n);
        for(int i = 0; i < n; i++){
            if(!ind[i]){
                q.push(i);
                inq[i] = 1;
            } 
        }
        while(q.size()){
            auto t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto v : adj[t]){
                ind[v]--;
                if(!ind[v] && !inq[v]){
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
        if(ans.size() < n) ans = vector<int>();
        return ans; 
    }
};