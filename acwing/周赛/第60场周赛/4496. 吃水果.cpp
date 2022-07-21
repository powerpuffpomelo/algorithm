// ###################################################### 版本1 ###################################################### //
// dp
#include <bits/stdc++.h>
using namespace std;

const int N = 2010, mod = 998244353;
int n, m, k;
int dp[N][N];   // 发了i个小朋友，其中j个小朋友拿到和左边不同

int main(){
    cin >> n >> m >> k;
    dp[1][0] = m;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= k && j < i; j++){
            dp[i][j] = dp[i - 1][j];
            if(j) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (m - 1ll)) % mod;   // 这里1ll，dp数组就无需long long了
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}