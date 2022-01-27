// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e5));
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(auto e : edges){
            int a = e[0], b = e[1], d = e[2];
            dist[a][b] = dist[b][a] = min(dist[a][b], d);
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int minnum = n, ans = -1;
        for(int i = 0; i < n; i++){
            int num = 0;
            for(int j = 0; j < n; j++){
                //cout << dist[i][j] << ' ';
                if(dist[i][j] <= distanceThreshold) num++;
            }
            //cout << endl;
            if(num <= minnum){
                minnum = num;
                ans = i;
            }
        }
        return ans;
    }
};