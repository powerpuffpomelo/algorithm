// ###################################################### 版本1 ###################################################### //
// dp[i][j][0]表示过了前i天，已经完成j比交易，且手上没有股票，的最大价值
// dp[i][j][1]表示过了前i天，已经完成j比交易，且手上有股票（手上的股是第j+1比交易买的股），的最大价值
// 此种情况下，dp[i][0][1]是需要计算的，所以j要从0开始遍历。
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 110, INF = 0x3f3f3f3f;
int n, m;
int w[N];
int dp[N][M][2];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    memset(dp, -INF, sizeof dp);
    for(int i = 0; i <= n; i++) dp[i][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j][0] = dp[i - 1][j][0];
            if(j > 0) dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + w[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - w[i]);
        }
    }
    int ans = 0;
    for(int j = 0; j <= m; j++) ans = max(ans, dp[n][j][0]);
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// dp[i][j][0]表示过了前i天，已经完成j比交易，且手上没有股票，的最大价值
// dp[i][j][1]表示过了前i天，开始进行第j比交易，且手上有股票（手上的股就是第j比交易买的股），的最大价值
// 此种情况下，dp[i][0][0]全是0，dp[i][0][1]全是-INF，因此无需额外计算j=0的结果，j从1开始遍历即可。
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 110, INF = 0x3f3f3f3f;
int n, m;
int w[N];
int dp[N][M][2];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    memset(dp, -INF, sizeof dp);
    for(int i = 0; i <= n; i++) dp[i][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + w[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - w[i]);
        }
    }
    int ans = 0;
    for(int j = 0; j <= m; j++) ans = max(ans, dp[n][j][0]);
    cout << ans << endl;
    return 0;
}