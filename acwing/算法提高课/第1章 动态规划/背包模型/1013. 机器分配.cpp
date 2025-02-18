// ###################################################### 版本1 ###################################################### //
// 分组背包+背包问题求具体方案
#include <bits/stdc++.h>
using namespace std;

const int N = 11, M = 16;
int n, m;
int dp[N][M], w[N][M];
int way[N];  // 第i个公司分配多少机器

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> w[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + w[i][k]);
            }
        }
    }
    cout << dp[n][m] << endl;
    int j = m;
    for(int i = n; i >= 1; i--){
        for(int k = 0; k <= j; k++){
            if(dp[i][j] == dp[i - 1][j - k] + w[i][k]){
                way[i] = k;
                j -= k;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << i << ' ' << way[i] << endl;
    return 0;
}