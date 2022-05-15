// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 210;
int n, k, x;
long long a[N], dp[N][N];
long long ans = -1;

int main(){
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            for(int u = max(0, i - k); u < i; u++){
                if(dp[u][j - 1] != -1){
                    dp[i][j] = max(dp[i][j], dp[u][j - 1] + a[i]);
                }
            }
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
        if(i >= n - k + 1) ans = max(ans, dp[i][x]);
    }
    cout << ans << endl;
    return 0;
}