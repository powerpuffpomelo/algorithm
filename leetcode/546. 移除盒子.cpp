// ###################################################### 版本1 ###################################################### //
// dp[i][j][k] 移除从i到j区间的盒子，而且最后移除第i个盒子，且最后移除个数为k的集合中，能获得的最大值
// g[i][j] = max dp[i][j][k] (1 <= k <= j - i + 1)
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size(), INF = 1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, -INF)));
        vector<vector<int>> g(n, vector<int>(n, -INF));
        for(int len = 1; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                for(int k = 1; k <= len; k++){
                    if(len == 1) dp[i][j][k] = 1;
                    else if(k == 1) dp[i][j][k] = 1 + g[i + 1][j];
                    else{
                        for(int u = i + 1; u <= j - k + 2; u++){
                            if(boxes[i] != boxes[u]) continue;
                            int t = 0;
                            if(i + 1 <= u - 1) t = g[i + 1][u - 1];
                            dp[i][j][k] = max(dp[i][j][k], t + dp[u][j][k - 1] - (k - 1) * (k - 1) + k * k);
                        }
                    }
                    g[i][j] = max(g[i][j], dp[i][j][k]);
                }
            }
        }
        return g[0][n - 1];
    }
};