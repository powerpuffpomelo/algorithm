// ###################################################### 版本2 ###################################################### //
// 混合背包，分类讨论，时间复杂度O(n*m*log(s))
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, v, w, s;
int dp[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> v >> w >> s;
        if(s == 0){ // 完全背包
            for(int j = v; j <= m; j++) dp[j] = max(dp[j], dp[j - v] + w);
        }else{
            if(s == -1) s = 1; // 01背包也是一种多重背包
            for(int k = 1; k <= s; k *= 2){ // 多重背包的二进制优化
                for(int j = m; j >= v * k; j--) dp[j] = max(dp[j], dp[j - v * k] + w * k);
                s -= k;
            }
            if(s){
                for(int j = m; j >= v * s; j--) dp[j] = max(dp[j], dp[j - v * s] + w * s);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, v, w, s;
int dp[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> v >> w >> s;
        if(s == -1){
            for(int j = m; j >= v; j--) dp[j] = max(dp[j], dp[j - v] + w);
        }
        else if(s == 0){
            for(int j = v; j <= m; j++) dp[j] = max(dp[j], dp[j - v] + w);
        }else{
            int x = 1;
            while(s >= x){
                for(int j = m; j >= v * x; j--) dp[j] = max(dp[j], dp[j - v * x] + w * x);
                s -= x;
                x *= 2;
            }
            if(s){
                for(int j = m; j >= v * s; j--) dp[j] = max(dp[j], dp[j - v * s] + w * s);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}