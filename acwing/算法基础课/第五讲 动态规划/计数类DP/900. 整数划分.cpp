// ###################################################### 版本1 ###################################################### //
// 题目中 nk从大到小，代表划分方式与顺序无关
// 于是可以当成完全背包来做，把体积为1到n的物品 恰好装入容量为n的背包中；
// dp[i][j]表示从前i个物品中选，恰好装入容量为j的背包中，共有多少种选法

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int dp[N];
int n;

int main(){
    cin >> n;
    dp[0] = 1;   // 装入体积为0的背包，方案是1种
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// dp[i][j] 代表 所有总和为i，个数为j的方案数
// dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j]，根据方案最小值是否为1来划分

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int dp[N][N];
int n;

int main(){
    cin >> n;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % mod;
        }
    }
    int ans = 0;
    for(int j = 1; j <= n; j++) ans = (ans + dp[n][j]) % mod;
    cout << ans << endl;
    return 0;
}