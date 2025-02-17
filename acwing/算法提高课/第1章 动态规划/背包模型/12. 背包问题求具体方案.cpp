// ###################################################### 版本1 ###################################################### //
// 关于为什么一开始要倒序背包：如果145和135都是最优方案的话，那么如果从后往前遍历（从dp[n][m]往前遍历）
// 选择5后不知道应该选3还是4，只能看到局部字典序最小，不能看到全局字典序最小。
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int dp[N][N], v[N], w[N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for(int i = n; i >= 1; i--){    // 倒序背包
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i + 1][j];
            if(j >= v[i]) dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
    }
    // 现在dp[1][V] 是最大价值

    int j = m;
    for(int i = 1; i <= n; i++){
        if(j >= v[i] && dp[i][j] == dp[i + 1][j - v[i]] + w[i]){
            cout << i << ' ';
            j -= v[i];
        }
    }
    return 0;
}