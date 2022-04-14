// ###################################################### 版本2 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
int g[N][N], dp[N][N];
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && j == 1) dp[i][j] = g[i][j];
            else{
                dp[i][j] = INF;
                if(i > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j] + g[i][j]);
                if(j > 1) dp[i][j] = min(dp[i][j], dp[i][j - 1] + g[i][j]);
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
int g[N][N], dp[N][N];
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
        }
        dp[i][0] = INF, dp[0][i] = INF;
    }
    dp[1][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}