#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 12, M = 1 << N;
long long dp[N][M];   // dp[i][j]代表第i-1行伸到第i行的小方块状态为j的方案数
bool st[M];   // 一个状态是否合法，如果有连续奇数空白则不合法
int n, m;

int main(){
    while(cin >> n >> m, n || m){
        for(int i = 0; i < 1 << n; i++){
            int cnt = 0;
            st[i] = true;
            for(int j = 0; j < n; j++){
                if(i >> j & 1){
                    if(cnt & 1) st[i] = false;
                    cnt = 0;
                }else{
                    cnt++;
                }
            }
            if(cnt & 1) st[i] = false;
        }
        memset(dp, 0, sizeof dp);   // long long 类型，似乎必须手动初始化
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 0; j < 1 << n; j++){
                for(int k = 0; k < 1 << n; k++){
                    if((j & k) == 0 && st[j | k]){
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}