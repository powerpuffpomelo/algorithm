// ###################################################### 版本1 ###################################################### //
// 自底向上
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510;
int g[N][N], dp[N][N];
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> g[i][j];
        }
    }
    for(int j = 1; j <= n; j++){
        dp[n][j] = g[n][j];
    }
    for(int i = n - 1; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + g[i][j];
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 自顶向下
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510, INF = -1e10;
int g[N][N], dp[N][N];
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= n + 1; j++){
            dp[i][j] = INF;
        }
    }
    dp[1][1] = g[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + g[i][j];
        }
    }
    int ans = INF;
    for(int j = 1; j <= n; j++) ans = max(ans, dp[n][j]);
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
// 自顶向下
#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 1e9;
int n;
int x, dp[N][N], ans = -INF;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i][i + 1] = -INF;
        for(int j = 1; j <= i; j++){
            cin >> x;
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + x;
            if(i == n) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}