// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int dp[N][N], v[N], w[N];
int n, V;

int main(){
    cin >> n >> V;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for(int i = n; i >= 1; i--){    // 倒序背包
        for(int j = 1; j <= V; j++){
            dp[i][j] = dp[i + 1][j];
            if(j >= v[i]) dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
    }
    // 现在dp[1][V] 是最大价值

    int j = V;
    for(int i = 1; i <= n; i++){
        if(j >= v[i] && dp[i][j] == dp[i + 1][j - v[i]] + w[i]){
            cout << i << ' ';
            j -= v[i];
        }
    }
    return 0;
}