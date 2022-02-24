// ###################################################### 版本1 ###################################################### //
// 节约空间，滚动数组

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int w[N], v[N];    // w 重量（体积）；v 价值
int dp[N];         // dp[i][j]代表 前i件物品放入体积不超j的背包的最大价值，一维是二维的省略版
int n, m;          // m 背包容量

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 朴素做法

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int w[N], v[N];    // w 重量（体积）；v 价值
int dp[N][N];      // dp[i][j]代表 前i件物品放入体积不超j的背包的最大价值，一维是二维的省略版
int n, m;          // m 背包容量

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i -  1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}