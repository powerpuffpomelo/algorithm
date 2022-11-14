// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adjr(k + 1), adjc(k + 1);
        vector<int> dr(k + 1), dc(k + 1);
        for(auto e : rowConditions){
            adjr[e[0]].push_back(e[1]);
            dr[e[1]]++;
        }
        for(auto e : colConditions){
            adjc[e[0]].push_back(e[1]);
            dc[e[1]]++;
        }
        vector<vector<int>> ans;
        vector<int> idxr(k + 1), idxc(k + 1);
        queue<int> q;
        vector<int> vis(k + 1);
        for(int i = 1; i <= k; i++){
            if(!dr[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
        int p = 0;
        while(q.size()){
            auto t = q.front();
            q.pop();
            idxr[t] = p++;
            for(int v : adjr[t]){
                if(!dr[v]){
                    return ans;
                }
                dr[v]--;
                if(!dr[v] && !vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        if(p != k) return ans;
        q = queue<int>();
        vis = vector<int>(k + 1, 0);
        for(int i = 1; i <= k; i++){
            if(!dc[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
        p = 0;
        while(q.size()){
            auto t = q.front();
            q.pop();
            idxc[t] = p++;
            for(int v : adjc[t]){
                if(!dc[v]){
                    return ans;
                }
                dc[v]--;
                if(!dc[v] && !vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        if(p != k) return ans;
        ans = vector<vector<int>>(k, vector<int>(k, 0));
        for(int i = 1; i <= k; i++){
            ans[idxr[i]][idxc[i]] = i;
        }
        return ans;
    }
};