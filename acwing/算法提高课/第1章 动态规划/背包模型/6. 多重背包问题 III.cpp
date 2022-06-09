// ###################################################### 版本1 ###################################################### //
// 单调队列优化，时间复杂度O(nm)
#include <bits/stdc++.h>
using namespace std;

const int V = 20010;
int n, m, v, w, s;
int dp[V], g[V], q[V];  // 因为是正向算的，需要用到i-1，为防止覆盖需要滚动二维dp数组/或者备份数组g

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> v >> w >> s;
        memcpy(g, dp, sizeof dp);
        for(int j = 0; j < v; j++){  // 按照余数分组，这样就可以用滑动窗口了
            int hh = 0, tt = -1;
            for(int k = j; k <= m; k += v){
                if(hh <= tt && q[hh] < k - s * v) hh++;
                while(hh <= tt && g[k] - g[q[tt]] >= (k - q[tt]) / v * w) tt--;
                q[++tt] = k;
                dp[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}