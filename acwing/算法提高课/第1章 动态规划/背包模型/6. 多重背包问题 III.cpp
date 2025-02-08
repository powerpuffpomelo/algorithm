// 完全背包：求所有前缀的最大值
// 多重背包：求滑动窗口内的最大值
// ###################################################### 版本2 ###################################################### //
// 单调队列优化，时间复杂度O(nm)
#include <bits/stdc++.h>
using namespace std;

const int V = 20010;
int n, m, v, w, s, l, r;
int dp[V], g[V], q[V];  // 因为是正向算的，需要用到i-1行的状态，为防止覆盖需要滚动二维dp数组/或者备份数组g

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> v >> w >> s;
        memcpy(g, dp, sizeof dp);
        for(int j = 0; j < v; j++){ // 按照余数分组，每个余数对应一个单调队列
            l = 0, r = -1; // 队首队尾
            for(int k = j; k <= m; k += v){
                while(l <= r && q[l] < k - v * s) l++;
                while(l <= r && g[k] >= g[q[r]] + (k - q[r]) / v * w) r--;
                q[++r] = k;
                dp[k] = g[q[l]] + (k - q[l]) / v * w;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int V = 20010;
int n, m, v, w, s;
int dp[V], g[V], q[V]; 

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> v >> w >> s;
        memcpy(g, dp, sizeof dp);
        for(int j = 0; j < v; j++){ 
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

