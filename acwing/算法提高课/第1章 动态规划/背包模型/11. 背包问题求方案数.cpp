// ###################################################### 版本1 ###################################################### //
// 优化成一维，时间复杂度O(n^3)
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n, m, dp[N], cnt[N]; 
// dp[i][j]代表使用前i种物品，总体积不超过j的最大价值
// cnt[i][j] 代表 dp[i][j] 对应的方案数

int main(){
    cin >> n >> m;
    for(int i = 0; i <= m; i++) cnt[i] = 1; // 不超过任何体积的背包 都可以什么也不选，就是一种方案
    for(int i = 0; i < n; i++){
        int v, w;
        cin >> v >> w;
        for(int j = m; j >= v; j--){
            int maxw = max(dp[j], dp[j - v] + w);
            int s = 0;
            if(dp[j] == maxw) s += cnt[j];
            if(dp[j - v] + w == maxw) s += cnt[j - v];
            dp[j] = maxw;
            cnt[j] = s % mod;
        }
    }
    cout << cnt[m] << endl;
    return 0;
}