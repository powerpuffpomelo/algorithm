// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    static const int N = 30, K = 110;
    double dp[K][N][N];
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    double knightProbability(int n, int k, int row, int column) {
        dp[0][row][column] = 1;
        for(int t = 1; t <= k; t++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dp[t - 1][i][j] == 0) continue;
                    for(int d = 0; d < 8; d++){
                        int a = i + dx[d], b = j + dy[d];
                        if(a >= 0 && a < n && b >= 0 && b < n){
                            dp[t][a][b] += dp[t - 1][i][j] / 8;
                        }
                    }
                }
            }
        }
        double ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans += dp[k][i][j];
            }
        }
        return ans;
    }
};