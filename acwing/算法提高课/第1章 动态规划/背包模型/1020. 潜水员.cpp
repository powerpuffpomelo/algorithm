// ###################################################### 版本1 ###################################################### //
// dp[i][j][k]代表 只能使用前i个物品，且氧气含量至少是j、氮气含量至少是k，所需气缸的重量总和最低值
// 状态表示意义不同（至多、恰好、至少），状态转移方程是一样的，但初始值和定义域不同
#include <bits/stdc++.h>
using namespace std;

const int M = 22, N = 80, INF = 1e9;
int m, n, k;
int dp[M][N];

int main(){
    cin >> m >> n >> k;
    fill(dp[0], dp[0] + M * N, INF);
    dp[0][0] = 0;
    for(int i = 0; i < k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = m; j >= 0; j--){
            for(int k = n; k >= 0; k--){
                dp[j][k] = min(dp[j][k], dp[max(0, j - a)][max(0, k - b)] + c);  // 可以为负
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}