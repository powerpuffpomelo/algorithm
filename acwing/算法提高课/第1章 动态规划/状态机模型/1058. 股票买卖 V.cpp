// ###################################################### 版本1 ###################################################### //
// dp[i][0]代表手中有股，dp[i][1]代表手中无股第一天，dp[i][2]代表手中无股第>=2天
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n;
int w[N];
int dp[N][3];

int main(){
    cin >> n;
    dp[0][0] = dp[0][1] = -INF, dp[0][2] = 0;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - w[i]);
        dp[i][1] = dp[i - 1][0] + w[i];
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
    }
    cout << max(dp[n][1], dp[n][2]) << endl;
    return 0;
}