// 状态机，01两种状态
// dp[i][j][0/1] 在第i天，已经完整进行j次交易，而且此刻手中不持有/持有股票的集合中，最大利润
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 110, INF = 1e9;
int n, k;
int a[N];
int dp[N][M][2];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    fill(dp[0][0], dp[0][0] + N * M * 2, -INF);
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j][0] = dp[i - 1][j][0];
            if(j) dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + a[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - a[i]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= k; i++) ans = max(ans, dp[n][i][0]);
    cout << ans << endl;
    return 0;
}