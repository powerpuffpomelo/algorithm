// 数据范围20，如果是dfs的话是20!复杂度，需要剪枝，但没法剪枝，所以不行，考虑状态压缩dp
// 集合：dp[i][j]所有已经走遍i中所有城市，且最后落脚在j城市的方案；属性：最小花费
// O(2^n * n^2)
#include <bits/stdc++.h>
using namespace std;

const int N = 20, INF = 1e6;  // N 如果是22都会mle
int n, g[N][N];
int dp[1 << N][N];
int ans = INF;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    fill(dp[0], dp[0] + (1 << N) * N, INF);
    dp[1][0] = 0;
    for(int i = 1; i < 1 << n; i += 2){
        for(int j = 1; j < n; j++){
            if(i >> j & 1){
                for(int k = 0; k < n; k++){
                    if((i - (1 << j)) >> k & 1){
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + g[k][j]);
                    }
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        ans = min(ans, dp[(1 << n) - 1][i] + g[i][0]);
    }
    cout << ans << endl;
    return 0;
}