// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        vector<int> dist(n, 1e8);    // 每个线路的最短距离
        unordered_map<int, vector<int>> g;  // 每站能换乘的线路
        queue<int> q;   // 装线路
        for(int i = 0; i < n; i++){
            for(auto x : routes[i]){
                if(x == source){
                    dist[i] = 1;
                    q.push(i);
                }
                g[x].push_back(i);
            }
        }
        while(q.size()){
            auto t = q.front();
            q.pop();
            for(auto x : routes[t]){
                if(x == target) return dist[t];
                for(auto i : g[x]){
                    if(dist[i] > dist[t] + 1){
                        dist[i] = dist[t] + 1;
                        q.push(i);
                    }
                }
            }
        }
        return -1;
    }
};